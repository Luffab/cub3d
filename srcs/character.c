/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:04:15 by fatilly           #+#    #+#             */
/*   Updated: 2021/04/21 17:28:07 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_player_right(t_cast *c)
{
	char	new_block;

	new_block = c->map[(int)c->posy]
	[(int)(c->posx + -c->diry * c->movespeed)];
	if (new_block != '1' && new_block != '2')
		c->posx += -c->diry * c->movespeed;
	new_block = c->map[(int)(c->posy
			+ c->dirx * c->movespeed)][(int)c->posx];
	if (new_block != '1' && new_block != '2')
		c->posy += c->dirx * c->movespeed;
}

void	ft_rotate_player_left(t_cast *c)
{
	char	new_block;

	new_block = c->map[(int)c->posy]
	[(int)(c->posx - -c->diry * c->movespeed)];
	if (new_block != '1' && new_block != '2')
		c->posx -= -c->diry * c->movespeed;
	new_block = c->map[(int)(c->posy
			- c->dirx * c->movespeed)][(int)c->posx];
	if (new_block != '1' && new_block != '2')
		c->posy -= c->dirx * c->movespeed;
}

void	ft_move_forward(t_cast *c)
{
	char	new_block;

	new_block = c->map[(int)c->posy]
	[(int)(c->posx + c->dirx * c->movespeed)];
	if (new_block != '1' && new_block != '2')
		c->posx += c->dirx * c->movespeed;
	new_block = c->map[(int)(c->posy
			+ c->diry * c->movespeed)][(int)c->posx];
	if (new_block != '1' && new_block != '2')
		c->posy += c->diry * c->movespeed;
}

void	ft_move_backward(t_cast *c)
{
	char	new_block;

	new_block = c->map[(int)c->posy]
	[(int)(c->posx - c->dirx * c->movespeed)];
	if (new_block != '1' && new_block != '2')
		c->posx -= c->dirx * c->movespeed;
	new_block = c->map[(int)(c->posy
			- c->diry * c->movespeed)][(int)c->posx];
	if (new_block != '1' && new_block != '2')
		c->posy -= c->diry * c->movespeed;
}

void	ft_rotate_player(t_cast *c)
{
	if (c->walkdirection == 1)
		ft_move_forward(c);
	if (c->walkdirection == -1)
		ft_move_backward(c);
	if (c->turndirection == 1)
		ft_rotate_player_right(c);
	if (c->turndirection == -1)
		ft_rotate_player_left(c);
	if (c->turndirection == -2)
		ft_rotate_camera_left(c);
	if (c->turndirection == 2)
		ft_rotate_camera_right(c);
}
