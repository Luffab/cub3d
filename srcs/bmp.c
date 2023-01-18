/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:30:41 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/24 17:36:03 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_good_bmp_name(char *s)
{
	int	i;

	i = 0;
	if (ft_strlen(s) != 6)
	{
		ft_putstr_fd("Error\nBAD_ARGUMENT", 1);
		return (0);
	}
	else if (ft_strncmp(s, "--save", 6) != 0)
	{
		ft_putstr_fd("Error\nBAD_ARGUMENT", 1);
		return (0);
	}
	return (1);
}

void	ft_init_bmp(t_cast *c)
{
	ft_bzero(c->header, 54);
	c->width = c->r[0];
	c->height = c->r[1];
	c->bytes_count = 32;
	c->width_in_bytes = ((c->width
				*c->bytes_count + 31) / 32) * 4;
	c->image_size = c->width_in_bytes * c->height;
	c->bytes_size = 40;
	c->bfoffbits = 54;
	c->file_size = 54 + c->image_size;
	c->biplanes = 1;
}

void	ft_fill_header(t_cast *c)
{
	ft_memcpy(c->header, "BM", 2);
	ft_memcpy(c->header + 2, &c->file_size, 4);
	ft_memcpy(c->header + 10, &c->bfoffbits, 4);
	ft_memcpy(c->header + 14, &c->bytes_size, 4);
	ft_memcpy(c->header + 18, &c->width, 4);
	ft_memcpy(c->header + 22, &c->height, 4);
	ft_memcpy(c->header + 26, &c->biplanes, 4);
	ft_memcpy(c->header + 28, &c->bytes_count, 4);
	ft_memcpy(c->header + 34, &c->image_size, 4);
	c->fd = open("./capture.bmp", O_TRUNC | O_WRONLY | O_CREAT, 0777);
}

void	ft_cub_save_bmp(t_cast *c)
{
	int		height_to_write;

	ft_init_bmp(c);
	ft_fill_header(c);
	height_to_write = c->height;
	write(c->fd, c->header, 54);
	while (height_to_write)
	{
		write(c->fd, c->data
			+ (height_to_write * c->width * 4), c->width * 4);
		height_to_write--;
	}
	ft_free_variable(c);
	free(c);
	close(c->fd);
}
