/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:28:07 by fatilly           #+#    #+#             */
/*   Updated: 2021/04/26 17:12:09 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sort_list(float **list)
{
	int		i;
	float	dist[2];
	float	temp[2];

	if (list && list[0])
	{
		i = 0;
		while (list[i + 1])
		{
			dist[0] = sqrt(list[i][0] * list[i][0] + list[i][1] * list[i][1]);
			dist[1] = sqrt(list[i + 1][0] * list[i + 1][0]
					+ list[i + 1][1] * list[i + 1][1]);
			if (dist[0] > dist[1])
			{
				temp[0] = list[i][0];
				temp[1] = list[i][1];
				list[i][0] = list[i + 1][0];
				list[i][1] = list[i + 1][1];
				list[i + 1][0] = temp[0];
				list[i + 1][1] = temp[1];
				i -= 1;
			}
			i++;
		}
	}
}

float	**ft_sprite_core(t_cast *c, int ready, int size, float *new)
{
	float	**new_dist;
	int		i;

	if (ready == 1)
		return (c->sprite_pos);
	new_dist = malloc(sizeof(float *) * (size + 2));
	i = 0;
	while (i < size)
	{
		new_dist[i] = c->sprite_pos[i];
		i++;
	}
	new_dist[i] = malloc(sizeof(float) * 2);
	new_dist[i][0] = new[0];
	new_dist[i][1] = new[1];
	new_dist[i + 1] = NULL;
	free(c->sprite_pos);
	return (new_dist);
}

float	**ft_add_sprite(t_cast *c)
{
	int		ready;
	int		size;
	float	new[2];

	size = 0;
	new[0] = c->mapx - c->posx + 0.5;
	new[1] = c->mapy - c->posy + 0.5;
	ready = 0;
	while (c->sprite_pos && c->sprite_pos[size])
	{
		if (c->sprite_pos[size][0] == new[0]
			&& c->sprite_pos[size][1] == new[1])
			ready = 1;
		size++;
	}
	return (ft_sprite_core(c, ready, size, new));
}

char	**ft_free_ftab(float **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}
