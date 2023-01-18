/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:30:09 by aviscogl          #+#    #+#             */
/*   Updated: 2021/02/10 11:30:09 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_walls_rgb_loop(t_cast *c, char *color, int x)
{
	int	i;

	i = c->drawstart;
	while (i < c->drawend)
	{
		c->data[x * 4 + c->size_line * i + 0] = color[0];
		c->data[x * 4 + c->size_line * i + 1] = color[1];
		c->data[x * 4 + c->size_line * i + 2] = color[2];
		c->data[x * 4 + c->size_line * i + 3] = color[3];
		i++;
	}
}

void	ft_walls_rgb(t_cast *c, int x)
{
	char	color[4];
	int		c_rgb;

	c_rgb = ft_rgbtoi(45, 70, 250);
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
	ft_walls_rgb_loop(c, color, x);
}

void	ft_pixel_to_image(t_cast *c, int x, int y, int rgb)
{
	if (c->endian == 1)
	{
		c->data[x * 4 + c->size_line * y + 3] = (rgb & 255);
		c->data[x * 4 + c->size_line * y + 2] = (rgb >> (1 * 8) & 255);
		c->data[x * 4 + c->size_line * y + 1] = (rgb >> (2 * 8) & 255);
		c->data[x * 4 + c->size_line * y + 0] = 0;
	}
	else
	{
		c->data[x * 4 + c->size_line * y + 0] = (rgb & 255);
		c->data[x * 4 + c->size_line * y + 1] = (rgb >> (1 * 8) & 255);
		c->data[x * 4 + c->size_line * y + 2] = (rgb >> (2 * 8) & 255);
		c->data[x * 4 + c->size_line * y + 3] = 0;
	}
}

void	ft_walls_textures(t_cast *c, int x)
{
	int		i;
	int		**texture;
	float	spot;

	texture = ft_get_good_texture(c);
	c->texx = (int)(c->wallx * (float)c->texwidth);
	c->step = (float)c->texheight / (float)c->lineheight;
	spot = (c->drawstart - c->r[1] / 2 + c->lineheight / 2) * c->step;
	i = c->drawstart;
	while (i < c->drawend)
	{
		c->texy = (int)spot;
		spot += c->step;
		ft_pixel_to_image(c, x, i, texture[c->texx][c->texy]);
		i++;
	}
}
