/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:06:59 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/24 17:33:49 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_char_count(char *s, char num)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == num)
			count++;
		i++;
	}
	return (count);
}

void	ft_verify_char(t_cast *c, char *s, char num, int which)
{
	if (which == 1)
	{
		if (ft_char_count(s, num) != 2)
		{
			c->c[0] = -1;
			c->c[1] = -1;
		}
	}
	else if (which == 2)
	{
		if (ft_char_count(s, num) != 2)
		{
			c->f[0] = -1;
			c->f[1] = -1;
		}
	}
}

void	ft_path_texture2(char *str, t_cast *c)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strnstr(str + i, "EA", 2) && str[i + 2] == ' ')
	{
		c->count_path++;
		if (c->ea)
			free(c->ea);
		c->ea = ft_strdup(str + i + 2);
	}
	else if (ft_strnstr(str + i, "NO", 2) && str[i + 2] == ' ')
	{
		c->count_path++;
		if (c->no)
			free(c->no);
		c->no = ft_strdup(str + i + 2);
	}
}

void	ft_free_variable(t_cast *c)
{
	free(c->no);
	free(c->so);
	free(c->ea);
	free(c->we);
	free(c->s);
	if (c->tnorth)
		ft_free_int_params(c->tnorth);
	if (c->tsouth)
		ft_free_int_params(c->tsouth);
	if (c->teast)
		ft_free_int_params(c->teast);
	if (c->twest)
		ft_free_int_params(c->twest);
	if (c->tsprite)
		ft_free_int_params(c->tsprite);
	free(c->img);
	free(c->data);
	free(c->win);
	if (c->mlx)
		mlx_del(c->mlx);
	ft_free_params(c->map);
	ft_free_params(c->file);
}

void	ft_free_int_params(int **file)
{
	int	i;

	i = 0;
	while (file[i] != 0)
		free(file[i++]);
	free(file);
}
