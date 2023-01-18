/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:27:09 by fatilly           #+#    #+#             */
/*   Updated: 2021/04/21 17:27:47 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_camera_left(t_cast *c)
{
	c->olddirx = c->dirx;
	c->dirx = c->dirx * cos(c->rotspeed) - c->diry * sin(c->rotspeed);
	c->diry = c->olddirx * sin(c->rotspeed) + c->diry * cos(c->rotspeed);
	c->oldplanex = c->planex;
	c->planex = c->planex * cos(c->rotspeed) - c->planey * sin(c->rotspeed);
	c->planey = c->oldplanex * sin(c->rotspeed) + c->planey * cos(c->rotspeed);
}

void	ft_rotate_camera_right(t_cast *c)
{
	c->olddirx = c->dirx;
	c->dirx = c->dirx * cos(-c->rotspeed) - c->diry * sin(-c->rotspeed);
	c->diry = c->olddirx * sin(-c->rotspeed) + c->diry * cos(-c->rotspeed);
	c->oldplanex = c->planex;
	c->planex = c->planex * cos(-c->rotspeed) - c->planey * sin(-c->rotspeed);
	c->planey = c->oldplanex * sin(-c->rotspeed) + c->planey
		* cos(-c->rotspeed);
}
