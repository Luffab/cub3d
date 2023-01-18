/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 03:45:27 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/24 16:12:21 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_path_texture(char *str, t_cast *c)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strnstr(str + i, "S", 1) && str[i + 1] == ' ')
	{
		c->count_path++;
		if (c->s)
			free(c->s);
		c->s = ft_strdup(str + i + 1);
	}
	else if (ft_strnstr(str + i, "SO", 2) && str[i + 2] == ' ')
	{
		c->count_path++;
		if (c->so)
			free(c->so);
		c->so = ft_strdup(str + i + 2);
	}
}

void	ft_get_resolution(char *str, t_cast *c)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strnstr(str + i, "R", 1))
	{
		i++;
		while (str[i] == ' ')
			i++;
		if (str[i])
			c->r[0] = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i])
			c->r[1] = ft_atoi(str + i);
	}
}

void	ft_get_rgb_c(char *str, t_cast *c)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strnstr(str + i, "C", 1))
	{
		i++;
		while (str[i] == ' ')
			i++;
		c->c[0] = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ',' || str[i] == ' ')
			i++;
		c->c[1] = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ',' || str[i] == ' ')
			i++;
		c->c[2] = ft_atoi(str + i);
		ft_verify_char(c, str, ',', 1);
	}
	ft_force_zero(c);
}

void	ft_get_rgb_f(char *str, t_cast *c)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strnstr(str + i, "F", 1))
	{
		i++;
		while (str[i] == ' ')
			i++;
		c->f[0] = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ',' || str[i] == ' ')
			i++;
		c->f[1] = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ',' || str[i] == ' ')
			i++;
		c->f[2] = ft_atoi(str + i);
		ft_verify_char(c, str, ',', 2);
	}
	ft_force_zero(c);
}

void	ft_force_zero(t_cast *c)
{
	if (c->c[0] == 0)
		c->c[0] = 1;
	if (c->c[1] == 0)
		c->c[1] = 1;
	if (c->c[2] == 0)
		c->c[2] = 1;
	if (c->f[0] == 0)
		c->f[0] = 1;
	if (c->f[1] == 0)
		c->f[1] = 1;
	if (c->f[2] == 0)
		c->f[2] = 1;
}
