/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:43:10 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/24 17:32:00 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_path_texture3(char *str, t_cast *c)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strnstr(str + i, "WE", 2) && str[i + 2] == ' ')
	{
		c->count_path++;
		if (c->we)
			free(c->we);
		c->we = ft_strdup(str + i + 2);
	}
}

int	ft_in_main(t_cast *c, int ac, char **av)
{
	if (!ft_valide_arg(av[1]))
	{
		ft_putstr_fd("Error\nBAD_FILE_EXTENSION", 1);
		return (0);
	}
	else if (ac == 3)
	{
		if (!ft_ready_for_bmp(c, av[1]) || !ft_good_bmp_name(av[2]))
			return (0);
		ft_putstr_fd("Screen !\n", 1);
		ft_render_bmp(c);
	}
	else if (!ft_ready_for_raycast(c, av[1]))
		return (0);
	return (1);
}

int	ft_verify_arg2(t_cast *c)
{
	if (c->c[0] > 255 || c->c[1] > 255 || c->c[2] > 255
		|| c->c[0] < 0 || c->c[1] < 0 || c->c[2] < 0)
	{
		ft_free_variable(c);
		ft_putstr_fd("Error\nCEILING_RGB_ERROR", 1);
		return (0);
	}
	if (c->count_path != 5)
	{
		ft_free_variable(c);
		ft_putstr_fd("Error\nDOUBLE_KEYS", 1);
		return (0);
	}
	return (1);
}
