/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:33:56 by aviscogl          #+#    #+#             */
/*   Updated: 2021/02/16 14:33:56 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	**ft_init_timg(void *mlx, char *path)
{
	void	*img;
	char	*data;
	int		**texture;
	int		tab[5];

	img = mlx_xpm_file_to_image(mlx, path, &tab[0], &tab[1]);
	if (!img)
		return (NULL);
	data = mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	if (!data)
	{
		mlx_destroy_image(mlx, img);
		return (NULL);
	}
	texture = ft_picture(data, tab);
	mlx_destroy_image(mlx, img);
	return (texture);
}

int	**ft_picture(char *data, int *tab)
{
	int	**picture;
	int	i;
	int	x;
	int	y;

	y = -1;
	picture = malloc(sizeof(int *) * (tab[0] + 1));
	while (++y < tab[0])
	{
		picture[y] = malloc(sizeof(int) * (tab[1] + 1));
		x = -1;
		while (++x < tab[1])
		{
			i = y * (tab[2] / 8) + x * tab[3];
			if (tab[4] == 1)
				picture[y][x] = ft_rgbtoi(data[i + 1],
						data[i + 2], data[i + 3]);
			else
				picture[y][x] = ft_rgbtoi(data[i + 2],
						data[i + 1], data[i + 0]);
		}
		picture[y][x] = -2147483648;
	}
	picture[y] = 0;
	return (picture);
}

int	ft_rgbtoi(int r, int g, int b)
{
	int	j;
	int	k;
	int	res;

	k = 23;
	j = 7;
	res = 0;
	while (j >= 0)
	{
		res += (r / (int)pow(2, j)) * pow(2, k--);
		r = r % (int)pow(2, j--);
	}
	j = 7;
	while (j >= 0)
	{
		res += (g / (int)pow(2, j)) * pow(2, k--);
		g = g % (int)pow(2, j--);
	}
	j = 7;
	while (j >= 0)
	{
		res += (b / (int)pow(2, j)) * pow(2, k--);
		b = b % (int)pow(2, j--);
	}
	return (res);
}

int	ft_init_texture(t_cast *c)
{
	c->tnorth = ft_init_timg(c->mlx, c->no);
	c->twest = ft_init_timg(c->mlx, c->we);
	c->teast = ft_init_timg(c->mlx, c->ea);
	c->tsouth = ft_init_timg(c->mlx, c->so);
	c->tsprite = ft_init_timg(c->mlx, c->s);
	if (!c->tnorth || !c->twest
		|| !c->teast || !c->tsouth || !c->tsprite)
		return (0);
	return (1);
}

int	**ft_get_good_texture(t_cast *c)
{
	int	**texture;

	if (c->face == 'W')
		texture = c->twest;
	else if (c->face == 'E')
		texture = c->teast;
	else if (c->face == 'S')
		texture = c->tsouth;
	else if (c->face == 'N')
		texture = c->tnorth;
	else
		texture = NULL;
	c->texwidth = 0;
	c->texheight = 0;
	while (texture[c->texwidth])
		c->texwidth++;
	while (texture[0][c->texheight] != -2147483648)
		c->texheight++;
	return (texture);
}
