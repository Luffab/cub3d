/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 13:21:22 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 11:13:01 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_initl(t_list *l)
{
	l->no = 0;
	l->so = 0;
	l->we = 0;
	l->ea = 0;
	l->s = 0;
	l->r[0] = -1;
	l->r[1] = -1;
	l->c[0] = -1;
	l->c[1] = -1;
	l->c[2] = -1;
	l->f[0] = -1;
	l->f[1] = -1;
	l->f[2] = -1;
	l->map = 0;
	l->south = 0;
	l->west = 0;
	l->east = 0;
	l->north = 0;
	l->upkey = 0;
	l->downkey = 0;
	l->rightkey = 0;
	l->leftkey = 0;
	l->planex = 0;
	l->planey = 0.66;
	l->dirx = -1;
	l->diry = 0;
}

void	cub3d(void)
{
	t_list *l;
	int res;

	l = malloc(sizeof(t_list));
	ft_initl(l);
	res = ft_checkerror(l);
	ft_init_window(l);
}