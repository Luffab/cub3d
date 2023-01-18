/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:27:54 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/24 17:31:47 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_verify_arg(t_cast *c)
{
	if (!c->ea || !c->no || !c->we || !c->so || !c->s)
	{
		ft_free_variable(c);
		ft_putstr_fd("Error\nTEXTURE_PATH_ERROR", 1);
		return (0);
	}
	if (c->f[0] > 255 || c->f[1] > 255 || c->f[2] > 255
		|| c->f[0] < 0 || c->f[1] < 0 || c->f[2] < 0)
	{
		ft_free_variable(c);
		ft_putstr_fd("Error\nFLOOR_RGB_ERROR", 1);
		return (0);
	}
	if (!ft_verify_arg2(c))
		return (0);
	return (1);
}

int	ft_verify_res(t_cast *c)
{
	if (c->r[0] <= 0 || c->r[1] <= 0)
	{
		ft_free_variable(c);
		ft_putstr_fd("Error\nRESOLUTION_ERROR", 1);
		return (0);
	}
	if (c->r[0] > 2560)
		c->r[0] = 2560;
	if (c->r[1] > 1440)
		c->r[1] = 1440;
	return (1);
}

int	ft_verify_map(t_cast *c)
{
	if (!ft_check_space_before_path(c))
	{
		ft_free_variable(c);
		ft_putstr_fd("Error\nTEXTURE_PATH_ERROR", 1);
		return (0);
	}
	if (!ft_check_char(c) || !ft_check_map(c, '0')
		|| !ft_check_map(c, '2') || !ft_check_nb_pos(c))
	{
		ft_free_variable(c);
		ft_putstr_fd("Error\nMAP_ERROR", 1);
		return (0);
	}
	return (1);
}

int	ft_ready_for_raycast(t_cast *c, char *file)
{
	if (!(ft_stock_file(c, file)))
	{
		ft_free_variable(c);
		ft_putstr_fd("Error\nFILE_ERROR", 1);
		return (0);
	}
	ft_separate_map(c);
	if (!ft_verify_res(c) || !ft_verify_arg(c) || !ft_verify_map(c))
		return (0);
	c->mlx = mlx_init();
	if (!ft_init_texture(c))
	{
		ft_free_variable(c);
		ft_putstr_fd("Error\nTEXTURE_ERROR", 1);
		return (0);
	}
	ft_get_init_pos(c);
	ft_get_init_orientation(c);
	ft_init_window(c);
	return (1);
}

int	ft_ready_for_bmp(t_cast *c, char *file)
{
	if (!(ft_stock_file(c, file)))
	{
		ft_free_variable(c);
		ft_putstr_fd("Error\nFILE_ERROR", 1);
		return (0);
	}
	ft_separate_map(c);
	if (!ft_verify_arg(c) || !ft_verify_map(c) || !ft_verify_res(c))
		return (0);
	c->mlx = mlx_init();
	if (!ft_init_texture(c))
	{
		ft_free_variable(c);
		ft_putstr_fd("Error\nTEXTURE_ERROR", 1);
		return (0);
	}
	ft_get_init_pos(c);
	ft_get_init_orientation(c);
	c->img = mlx_new_image(c->mlx, c->r[0], c->r[1]);
	c->data = mlx_get_data_addr(c->img, &(c->bpp),
			&(c->size_line), &(c->endian));
	c->win = mlx_new_window(c->mlx, c->r[0], c->r[1], "CUB3D");
	return (1);
}
