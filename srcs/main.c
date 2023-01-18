/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 03:45:35 by fatilly           #+#    #+#             */
/*   Updated: 2021/11/29 00:09:57 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_t_cast(t_cast *c)
{
	c->no = 0;
	c->so = 0;
	c->we = 0;
	c->ea = 0;
	c->s = 0;
	c->r[0] = -1;
	c->r[1] = -1;
	c->c[0] = -1;
	c->c[1] = -1;
	c->c[2] = -1;
	c->f[0] = -1;
	c->f[1] = -1;
	c->f[2] = -1;
	c->map = 0;
	c->file = 0;
	c->color = 0;
	c->endian = 1;
	c->rotspeed = 0.10;
	c->movespeed = 0.06;
	c->bpp = 32;
	c->fov = 66 * (M_PI / 180);
	c->data = NULL;
	c->count_path = 0;
}

int	ft_close_win(void)
{
	exit(0);
}

int	ft_valide_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		i++;
	i++;
	if (str[i] == 'c' && str[i + 1] == 'u' && str[i + 2] == 'b'
		&& str[i + 3] == '\0')
		return (1);
	return (0);
}

int	ft_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (0);
	return (fd);
}

int	main(int ac, char **av)
{
	t_cast	*c;
	int		res;

	c = malloc(sizeof(t_cast));
	res = 0;
	ft_init_t_cast(c);
	if (ac > 3)
	{
		ft_putstr_fd("Error\nTOO_MANY_ARGUMENT", 1);
		res = 1;
	}
	else if (ac < 2)
	{
		ft_putstr_fd("Error\nNOT_ENOUGH_ARGUMENT", 1);
		res = 1;
	}
	else if (!ft_in_main(c, ac, av))
		res = 1;
	if (res == 1)
	{
		free(c);
		return (0);
	}
	return (1);
}
