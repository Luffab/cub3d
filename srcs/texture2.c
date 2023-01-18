/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:54:45 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/18 16:57:30 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ceiling_rgb_loop(t_cast *c, char *color, int x)
{
	int	i;

	i = 0;
	while (i < c->drawstart)
	{
		c->data[x * 4 + c->size_line * i + 0] = color[0];
		c->data[x * 4 + c->size_line * i + 1] = color[1];
		c->data[x * 4 + c->size_line * i + 2] = color[2];
		c->data[x * 4 + c->size_line * i + 3] = color[3];
		i++;
	}
}

void	ft_ceiling_rgb(t_cast *c, int x)
{
	char	color[4];
	int		c_rgb;

	c_rgb = ft_rgbtoi(c->c[0], c->c[1], c->c[2]);
	if (c->endian == 1)
	{
		color[0] = 0;
		color[1] = (c_rgb >> (2 * 8) & 255);
		color[2] = (c_rgb >> (1 * 8) & 255);
		color[3] = (c_rgb & 255);
	}
	else
	{
		color[0] = (c_rgb & 255);
		color[1] = (c_rgb >> (1 * 8) & 255);
		color[2] = (c_rgb >> (2 * 8) & 255);
		color[3] = 0;
	}
	ft_ceiling_rgb_loop(c, color, x);
}

void	ft_floor_rgb_loop(t_cast *c, char *color, int x)
{
	int	i;

	i = c->drawend;
	while (i < c->r[1])
	{
		c->data[x * 4 + c->size_line * i + 0] = color[0];
		c->data[x * 4 + c->size_line * i + 1] = color[1];
		c->data[x * 4 + c->size_line * i + 2] = color[2];
		c->data[x * 4 + c->size_line * i + 3] = color[3];
		i++;
	}
}

void	ft_floor_rgb(t_cast *c, int x)
{
	char	color[4];
	int		c_rgb;

	c_rgb = ft_rgbtoi(c->f[0], c->f[1], c->f[2]);
	if (c->endian == 1)
	{
		color[0] = 0;
		color[1] = (c_rgb >> (2 * 8) & 255);
		color[2] = (c_rgb >> (1 * 8) & 255);
		color[3] = (c_rgb & 255);
	}
	else
	{
		color[0] = (c_rgb & 255);
		color[1] = (c_rgb >> (1 * 8) & 255);
		color[2] = (c_rgb >> (2 * 8) & 255);
		color[3] = 0;
	}
	ft_floor_rgb_loop(c, color, x);
}
