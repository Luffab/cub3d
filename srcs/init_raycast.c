/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:27:49 by fatilly           #+#    #+#             */
/*   Updated: 2021/11/24 00:31:08 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_render_cast(t_cast *c)
{
	double	*buffer;

	mlx_clear_window(c->mlx, c->win);
	c->sprite_pos = NULL;
	buffer = malloc(sizeof(double) * c->r[0]);
	ft_rotate_player(c);
	ft_wall_casting(c, &buffer);
	ft_sort_list(c->sprite_pos);
	ft_screen_sprite(c, buffer);
	mlx_put_image_to_window(c->mlx, c->win, c->img, 0, 0);
	free(buffer);
	return (1);
}

void	ft_render_bmp(t_cast *c)
{
	double	*buffer;

	mlx_clear_window(c->mlx, c->win);
	c->sprite_pos = NULL;
	buffer = malloc(sizeof(double) * c->r[0]);
	ft_rotate_player(c);
	ft_wall_casting(c, &buffer);
	ft_sort_list(c->sprite_pos);
	ft_screen_sprite(c, buffer);
	ft_cub_save_bmp(c);
	free(buffer);
}

int	ft_player_input(int key, t_cast *c)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		c->walkdirection = 1;
	if (key == 1)
		c->walkdirection = -1;
	if (key == 2)
		c->turndirection = 1;
	if (key == 0)
		c->turndirection = -1;
	if (key == 123)
		c->turndirection = 2;
	if (key == 124)
		c->turndirection = -2;
	ft_render_cast(c);
	return (0);
}

int	ft_player_input_release(int key, t_cast *c)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		c->walkdirection = 0;
	if (key == 1)
		c->walkdirection = 0;
	if (key == 2)
		c->turndirection = 0;
	if (key == 0)
		c->turndirection = 0;
	if (key == 123)
		c->turndirection = 0;
	if (key == 124)
		c->turndirection = 0;
	ft_render_cast(c);
	return (0);
}

void	ft_init_window(t_cast *c)
{
	c->img = mlx_new_image(c->mlx, c->r[0], c->r[1]);
	c->data = mlx_get_data_addr(c->img, &(c->bpp),
			&(c->size_line), &(c->endian));
	c->win = mlx_new_window(c->mlx, c->r[0], c->r[1], "CUB3D");
	mlx_hook(c->win, 3, 0, ft_player_input_release, c);
	mlx_hook(c->win, 2, 0, ft_player_input, c);
	mlx_hook(c->win, 17, 0, ft_close_win, (void *)0);
	mlx_loop_hook(c->mlx, ft_render_cast, c);
	mlx_loop(c->mlx);
}
