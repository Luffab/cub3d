/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:12:41 by aviscogl          #+#    #+#             */
/*   Updated: 2021/02/08 13:12:41 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_wall_casting(t_cast *c, double **buffer)
{
	int	x;

	x = -1;
	while (++x < c->r[0])
	{
		c->camerax = 2 * x / (double)c->r[0] - 1;
		c->raydirx = c->dirx + c->planex * c->camerax;
		c->raydiry = c->diry + c->planey * c->camerax;
		c->mapx = (int)c->posx + 0.5;
		c->mapy = (int)c->posy + 0.5;
		c->deltadistx = fabs(1 / c->raydirx);
		c->deltadisty = fabs(1 / c->raydiry);
		ft_calculate_step(c);
		c->hit = 0;
		ft_side_hit(c);
		ft_side(c);
		c->wallx -= floor(c->wallx);
		c->lineheight = (int)(c->r[1] / c->perpwalldist);
		ft_calculate_pixel_wallx(c);
		ft_ceiling_rgb(c, x);
		ft_floor_rgb(c, x);
		ft_walls_textures(c, x);
		buffer[0][x] = c->perpwalldist;
	}
	return (0);
}

void	ft_side(t_cast *c)
{
	if (c->side == 0)
	{
		c->perpwalldist = (c->mapx - c->posx + (1 - c->stepx) / 2) / c->raydirx;
		if (c->raydirx < 0)
			c->face = 'W';
		else
			c->face = 'E';
		c->wallx = c->posy + c->perpwalldist * c->raydiry;
	}
	else
	{
		c->perpwalldist = (c->mapy - c->posy + (1 - c->stepy) / 2) / c->raydiry;
		if (c->raydiry < 0)
			c->face = 'N';
		else
			c->face = 'S';
		c->wallx = c->posx + c->perpwalldist * c->raydirx;
	}
}

void	ft_calculate_step(t_cast *c)
{
	if (c->raydirx < 0)
	{
		c->stepx = -1;
		c->sidedistx = (c->posx - c->mapx) * c->deltadistx;
	}
	else
	{
		c->stepx = 1;
		c->sidedistx = (c->mapx + 1.0 - c->posx) * c->deltadistx;
	}
	if (c->raydiry < 0)
	{
		c->stepy = -1;
		c->sidedisty = (c->posy - c->mapy) * c->deltadisty;
	}
	else
	{
		c->stepy = 1;
		c->sidedisty = (c->mapy + 1.0 - c->posy) * c->deltadisty;
	}
}

void	ft_side_hit(t_cast *c)
{
	while (c->hit == 0)
	{
		if (c->sidedistx < c->sidedisty)
		{
			c->sidedistx += c->deltadistx;
			c->mapx += c->stepx;
			c->side = 0;
		}
		else
		{
			c->sidedisty += c->deltadisty;
			c->mapy += c->stepy;
			c->side = 1;
		}
		if (c->map[c->mapy][c->mapx] == '2')
			c->sprite_pos = ft_add_sprite(c);
		if (c->map[c->mapy][c->mapx] == '1')
			c->hit = 1;
	}
}

void	ft_calculate_pixel_wallx(t_cast *c)
{
	c->drawstart = -c->lineheight / 2 + c->r[1] / 2;
	if (c->drawstart < 0)
		c->drawstart = 0;
	c->drawend = c->lineheight / 2 + c->r[1] / 2;
	if (c->drawend > c->r[1])
		c->drawend = c->r[1];
	c->textnum = c->map[c->mapy][c->mapx] - 1;
}
