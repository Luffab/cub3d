/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:07:16 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/18 15:18:18 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_init_pos(t_cast *c)
{
	int	x;
	int	y;

	y = 0;
	while (c->map[y] != 0)
	{
		x = 0;
		while (c->map[y][x] != '\0')
		{
			if (c->map[y][x] == 'N' || c->map[y][x] == 'S'
				|| c->map[y][x] == 'W' || c->map[y][x] == 'E')
			{
				ft_is_ns(c, c->map[y][x]);
				ft_is_ew(c, c->map[y][x]);
				c->posx = x + 0.5;
				c->posy = y + 0.5;
				c->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	ft_get_init_orientation(t_cast *c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (c->map[y] != 0)
	{
		while (c->map[y][x] != '\0')
		{
			if (c->map[y][x] == 'N')
				c->north = 1;
			else if (c->map[y][x] == 'S')
				c->south = 1;
			else if (c->map[y][x] == 'W')
				c->west = 1;
			else if (c->map[y][x] == 'E')
				c->east = 1;
			x++;
		}
		y++;
	}
}

int	ft_stock_file(t_cast *c, char *file)
{
	char	*s;
	char	*line;
	int		fd;
	int		ret;

	s = ft_strdup("");
	fd = ft_open_file(file);
	if (!fd)
		return (0);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			return (0);
		line = ft_putbackline(line);
		s = ft_strjoin(s, line);
	}
	c->file = ft_split(s, '\n');
	free(s);
	return (1);
}

int	ft_len_of_map(char **str)
{
	int	x;

	x = 0;
	while (str[x] != 0)
		x++;
	return (x);
}

char	*ft_putbackline(char *str)
{
	char	*s;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str) + 1;
	s = malloc(i * sizeof(char) + 1);
	while (str[j])
	{
		s[j] = str[j];
		j++;
	}
	s[j] = '\n';
	s[j + 1] = '\0';
	free(str);
	return (s);
}
