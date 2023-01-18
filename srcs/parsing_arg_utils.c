/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 03:45:13 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/24 15:45:57 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_space_count(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (i);
}

int	ft_check_space_before_path(t_cast *c)
{
	if (c->no[0] == ' ' && c->so[0] == ' ' && c->we[0] == ' '
		&& c->ea[0] == ' ' && c->s[0] == ' ')
	{
		c->s = ft_substr(c->s, ft_space_count(c->s), ft_strlen(c->s));
		c->no = ft_substr(c->no, ft_space_count(c->no), ft_strlen(c->no));
		c->so = ft_substr(c->so, ft_space_count(c->so), ft_strlen(c->so));
		c->we = ft_substr(c->we, ft_space_count(c->we), ft_strlen(c->we));
		c->ea = ft_substr(c->ea, ft_space_count(c->ea), ft_strlen(c->ea));
		return (1);
	}
	else
		return (0);
}

int	ft_count_arg(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

int	ft_line_contain_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_separate_map(t_cast *c)
{
	int	y;
	int	x;
	int	len;

	y = -1;
	x = 0;
	len = ft_len_of_map(c->file);
	c->map = (char **)malloc(len * sizeof(char *));
	while (c->file[++y] != 0)
	{
		if (!c->ea || !c->so || !c->no || !c->we || !c->s || c->r[0] < 0
			|| c->r[1] < 0 || c->c[0] < 0 || c->c[1] < 0 || c->c[2] < 0
			|| c->f[0] < 0 || c->f[1] < 0 || c->f[2] < 0)
		{
			ft_path_texture(c->file[y], c);
			ft_path_texture2(c->file[y], c);
			ft_path_texture3(c->file[y], c);
			ft_get_resolution(c->file[y], c);
			ft_get_rgb_f(c->file[y], c);
			ft_get_rgb_c(c->file[y], c);
		}
		else
			c->map[x++] = ft_strdup(c->file[y]);
	}
	c->map[x] = 0;
}
