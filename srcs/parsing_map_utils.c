/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:07:49 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/19 17:13:21 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_one(char *str, char *str1)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i + 1] == '\0' && (str1[i + 1] == '0' || str1[i + 1] == '2'))
			return (0);
		if (str[i + 1] == '\0' && str1[i + 1] == '1')
			if ((str1[i + 2] == '0' || str1[i + 2] == '2') && str[i + 2] != '\0')
				return (0);
		if (str[i] != '1' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_map_norme(t_cast *c, int x, int y, char num)
{
	if (!ft_check_map_norme_x0(c, x, y, num)
		|| !ft_check_map_norme_x1(c, x, y, num))
		return (0);
	return (1);
}

int	ft_check_map(t_cast *c, char num)
{
	int	x;
	int	y;
	int	len;

	y = 0;
	len = ft_len_of_map(c->map);
	if (!ft_check_one(c->map[0], c->map[1])
		|| !ft_check_one(c->map[len - 1], c->map[len - 2]))
		return (0);
	while (c->map[++y] != 0)
	{
		x = -1;
		len = ft_strlen(c->map[y]);
		while (c->map[y][++x] != '\0')
		{
			if (c->map[y][len - 1] == num || c->map[y][0] == num)
				return (0);
			else if (c->map[y][x] == '0' || c->map[y][x] == '2')
			{
				if (!ft_check_map_norme(c, x, y, ' '))
					return (0);
			}
		}
	}
	return (1);
}

int	ft_check_char(t_cast *c)
{
	int	x;
	int	y;

	y = 0;
	while (c->map[y] != 0)
	{
		x = 0;
		while (c->map[y][x] != '\0')
		{
			if (c->map[y][x] != ' ' && c->map[y][x] != '0'
				&& c->map[y][x] != '1'
				&& c->map[y][x] != '2' && c->map[y][x] != 'N'
				&& c->map[y][x] != 'S' && c->map[y][x] != 'W'
				&& c->map[y][x] != 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_nb_pos(t_cast *c)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (c->map[y] != 0)
	{
		x = 0;
		while (c->map[y][x] != '\0')
		{
			if (c->map[y][x] == 'N' || c->map[y][x] == 'S'
			|| c->map[y][x] == 'W' || c->map[y][x] == 'E')
				i++;
			x++;
		}
		y++;
	}
	if (i == 0 || i > 1)
		return (0);
	return (1);
}
