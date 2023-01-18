/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:33:26 by fatilly           #+#    #+#             */
/*   Updated: 2021/04/21 17:47:38 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_sprite_infos(t_cast *c)
{
	int	i;

	i = 0;
	c->texheight = 0;
	c->texwidth = 0;
	while (c->tsprite[c->texwidth])
		c->texwidth++;
	while (c->tsprite[c->texwidth - 1][c->texheight] != -2147483648)
		c->texheight++;
	while (c->sprite_pos && c->sprite_pos[i])
		i++;
	i--;
	return (i);
}

void	ft_sprite_calc1(t_cast *c, int i)
{
	float	inv;

	inv = 1.0 / (c->planex * c->diry - c->dirx * c->planey);
	c->transform[0] = inv * (c->diry * c->sprite_pos[i][0]
			- c->dirx * c->sprite_pos[i][1]);
	c->transform[1] = inv * (-c->planey * c->sprite_pos[i][0]
			+ c->planex * c->sprite_pos[i][1]);
	c->sprite_screen_x = (int)(c->r[0] / 2) *(1 + c->transform[0]
			/ c->transform[1]);
}

int	ft_sprite_calc(t_cast *c, int i)
{
	int	sprite_size;

	ft_sprite_calc1(c, i);
	sprite_size = abs((int)(c->r[1] / c->transform[1]));
	c->sprite_start_end[0][1] = -sprite_size / 2 + c->r[1] / 2;
	if (c->sprite_start_end[0][1] < 0)
		c->sprite_start_end[0][1] = 0;
	c->sprite_start_end[1][1] = sprite_size / 2 + c->r[1] / 2;
	if (c->sprite_start_end[1][1] >= c->r[1])
		c->sprite_start_end[1][1] = c->r[1] - 1;
	c->sprite_start_end[0][0] = -sprite_size / 2 + c->sprite_screen_x;
	if (c->sprite_start_end[0][0] < 0)
		c->sprite_start_end[0][0] = 0;
	c->sprite_start_end[1][0] = sprite_size / 2 + c->sprite_screen_x;
	if (c->sprite_start_end[1][0] >= c->r[0])
		c->sprite_start_end[1][0] = c->r[0] - 1;
	return (sprite_size);
}

void	ft_print_sprite(t_cast *c, double *buffer)
{
	int	x;
	int	y;

	y = c->sprite_start_end[0][0];
	while (y < c->sprite_start_end[1][0])
	{
		c->texx = (int)(256 * (y - (-c->sprite_size / 2 + c->sprite_screen_x))
				*c->texwidth / c->sprite_size) / 256;
		if (c->transform[1] > 0 && y > 0 && y < c->r[0]
			&& c->transform[1] < buffer[y])
		{
			x = c->sprite_start_end[0][1];
			while (x < c->sprite_start_end[1][1])
			{
				c->texy = (((x * 256 - c->r[1] * 128 + c->sprite_size * 128)
							* c->texheight) / c->sprite_size) / 256;
				if (c->tsprite[c->texx][c->texy] != 0)
					ft_pixel_to_image(c, y, x, c->tsprite[c->texx][c->texy]);
				x++;
			}
		}
		y++;
	}
}

void	ft_screen_sprite(t_cast *c, double *buffer)
{
	int	i;

	i = ft_init_sprite_infos(c);
	while (i >= 0)
	{
		c->sprite_size = ft_sprite_calc(c, i);
		ft_print_sprite(c, buffer);
		i--;
	}
	ft_free_ftab(c->sprite_pos);
}
