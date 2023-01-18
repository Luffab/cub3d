/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:41:39 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/19 15:10:00 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_is_ns(t_cast *c, char pos)
{
	if (pos == 'N')
	{
		c->dirx = 0;
		c->diry = -1;
		c->planex = c->fov;
		c->planey = 0;
	}
	else if (pos == 'S')
	{
		c->dirx = 0;
		c->diry = 1;
		c->planex = -c->fov;
		c->planey = 0;
	}
}

void	ft_is_ew(t_cast *c, char pos)
{
	if (pos == 'E')
	{
		c->dirx = 1;
		c->diry = 0;
		c->planex = 0;
		c->planey = c->fov;
	}
	else if (pos == 'W')
	{
		c->dirx = -1;
		c->diry = 0;
		c->planex = 0;
		c->planey = -c->fov;
	}
}

void	ft_free_params(char **file)
{
	int	i;

	i = 0;
	while (file[i] != 0)
		free(file[i++]);
	free(file);
}

int	ft_check_map_norme_x0(t_cast *c, int x, int y, char num)
{
	int	leny;

	leny = ft_len_of_map(c->map);
	if (x == 0)
	{
		if (y == 0)
		{
			if (c->map[y][x + 1] == num
			|| c->map[y + 1][x] == num)
				return (0);
		}
		else if (y == ft_len_of_map(c->map) - 1)
		{
			if (c->map[y][x + 1] == num
			|| c->map[y - 1][x] == num)
				return (0);
		}
		else
		{
			if (c->map[y][x + 1] == num
			|| c->map[y - 1][x] == num || c->map[y + 1][x] == num)
				return (0);
		}
	}
	return (1);
}

int	ft_check_map_norme_x1(t_cast *c, int x, int y, char num)
{
	int	lenx;

	lenx = ft_strlen(c->map[y]);
	if (x > 0 && x < lenx - 1)
	{
		if (y == 0)
		{
			if (c->map[y][x - 1] == num || c->map[y][x + 1] == num
			|| c->map[y + 1][x] == num)
				return (0);
		}
		else if (y == ft_len_of_map(c->map) - 1)
		{
			if (c->map[y][x - 1] == num || c->map[y][x + 1] == num
			|| c->map[y - 1][x] == num)
				return (0);
		}
		else
		{
			if (c->map[y][x - 1] == num || c->map[y][x + 1] == num
			|| c->map[y - 1][x] == num || c->map[y + 1][x] == num)
				return (0);
		}
	}
	return (1);
}
