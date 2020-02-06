/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_initcub.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 00:23:01 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 18:09:46 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int    draw(t_list *l)
{
	l->x = 0;
    while (l->x < l->r[0])
    {
        l->camerax = 2 * l->x / (double)l->r[0] - 1;
        l->raydirx = l->dirx + l->planex * l->camerax;
        l->raydiry = l->diry + l->planey * l->camerax;
        l->mapx = (int)l->posx;
        l->mapy = (int)l->posy;
        l->deltadistx = fabs(1 / l->raydirx);
        l->deltadisty = fabs(1 / l->raydiry);
        l->hit = 0;
        if (l->raydirx < 0)
        {
            l->stepx = -1;
            l->sidedistx = (l->posx - l->mapx) * l->deltadistx;
        }
        else
        {
            l->stepx = 1;
            l->sidedistx = (l->mapx + 1.0 - l->posx) * l->deltadistx;
        }
        if (l->raydiry < 0)
        {
            l->stepy = -1;
            l->sidedisty = (l->posy - l->mapy) * l->deltadisty;
        }
        else
        {
            l->stepy = 1;
            l->sidedisty = (l->mapy + 1.0 - l->posy) * l->deltadisty;
        }
        while (l->hit == 0)
        {
            if (l->sidedistx < l->sidedisty)
            {
                l->sidedistx += l->deltadistx;
                l->mapx += l->stepx;
                l->side = 0;    
            }
            else
            {
                l->sidedisty += l->deltadisty;
                l->mapy += l->stepy;
                l->side = 1;
            }
            if (l->map[l->mapy][l->mapx] != '0')
                l->hit = 1;
        }
        if (l->side == 0)
            l->perpwalldist = (l->mapx - l->posx + (1 - l->stepx) / 2) / l->raydirx;
        else
            l->perpwalldist = (l->mapy - l->posy + (1 - l->stepy) / 2) / l->raydiry;
        l->lineheight = (long int)(l->r[1] / l->perpwalldist);
        l->drawstart = -l->lineheight / 2 + l->r[1] / 2;
        if (l->drawstart < 0)
            l->drawstart = 0;
        l->drawend = l->lineheight / 2 + l->r[1] / 2;
        if (l->drawend >= l->r[1])
            l->drawend = l->r[1] - 1;
		l->color = 0x0000FF;
        if (l->side == 1)
            l->color /= 2;
        novatempus(l);
		l->x++;
    }
	keyhooks(l);
	mlx_clear_window(l->mlx, l->win);
	mlx_put_image_to_window(l->mlx, l->win, l->img, 0, 0);
	return (1);
}

void	redraw(t_list *l)
{
	mlx_destroy_image(l->mlx, l->img);
	l->img = mlx_new_image(l->mlx, l->r[0], l->r[1]);
	l->data = (int *)mlx_get_data_addr(l->img, &(l->bpp), &(l->size_line), &(l->endian));
    draw(l);
	mlx_clear_window(l->mlx, l->win);
	mlx_put_image_to_window(l->mlx, l->win, l->img, 0, 0);
}

void	upmove(t_list *g)
{
	int x;
	int y;
	x = (int)(g->posx + g->dirx * g->movespeed);
	y = (int)(g->posy + g->diry * g->movespeed);
	if (g->map[y][x] == '0')
	{
		g->posx += g->dirx * g->movespeed;
		g->posy += g->diry * g->movespeed;
	}
}

void	downmove(t_list *g)
{
	int x;
	int y;
	x = (int)(g->posx - g->dirx * g->movespeed);
	y = (int)g->posy;
	if (g->map[y][x] == '0')
	{
		g->posx -= g->dirx * g->movespeed;
		g->posy -= g->diry * g->movespeed;
	}
}

void	rightmove(t_list *g)
{
		g->olddirx = g->dirx;
		g->dirx = g->dirx * cos(-g->rotspeed) - g->diry * sin(-g->rotspeed);
		g->diry = g->olddirx * sin(-g->rotspeed) + g->diry * cos(-g->rotspeed);
		g->oldplanex = g->planex;
		g->planex = g->planex * cos(-g->rotspeed) -
			g->planey * sin(-g->rotspeed);
		g->planey = g->oldplanex * sin(-g->rotspeed) +
			g->planey * cos(-g->rotspeed);
}

void	leftmove(t_list *g)
{
		g->olddirx = g->dirx;
		g->dirx = g->dirx * cos(g->rotspeed) - g->diry * sin(g->rotspeed);
		g->diry = g->olddirx * sin(g->rotspeed) +
			g->diry * cos(g->rotspeed);
		g->oldplanex = g->planex;
		g->planex = g->planex * cos(g->rotspeed) - g->planey * sin(g->rotspeed);
		g->planey = g->oldplanex * sin(g->rotspeed) +
			g->planey * cos(g->rotspeed);
}

int		keyhooks(t_list *g)
{
	if (g->upkey == 1)
		upmove(g);
	if (g->downkey == 1)
		downmove(g);
	if (g->leftkey == 1)
		leftmove(g);
	if (g->rightkey == 1)
		rightmove(g);
	return (0);
}

int				close_win(t_list *l)
{
	mlx_destroy_window(l->mlx, l->win);
	exit (0);
}


int		vaultmovement(int key, t_list *l)
{
	if (key == 53)
			exit(0);
	if (key == 126 || key == 13)
		l->upkey = 1;
	if (key == 125 || key == 1)
		l->downkey = 1;
	if (key == 123 || key == 0)
		l->leftkey = 1;
	if (key == 124 || key == 2)
		l->rightkey = 1;
	keyhooks(l);
	return (0);
}

int	vaultmovementtoggle(int key, t_list *l)
{
	if (key == 126 || key == 13)
		l->upkey = 0;
	if (key == 125 || key == 1)
		l->downkey = 0;
	if (key == 123 || key == 0)
		l->leftkey = 0;
	if (key == 124 || key == 2)
		l->rightkey = 0;
	keyhooks(l);
	return (0);
	}

int		repeat(t_list *l)
{
	mlx_hook(l->win, 2, 0, vaultmovement, l);
	mlx_hook(l->win, 3, 0, vaultmovementtoggle, l);
	mlx_hook(l->win, 17, 0, close_win, l);
	return (0);
}

int		ft_color(int r, int g, int b)
{
	int		color;

	color = 0;
	color += r * 256 * 256;
	color += g * 256;
	color += b;
	return (color);
}

void			novatempus(t_list *l)
{
	int i;

	i = 0;
	while (i < l->drawstart)
	{
		l->data[i * l->r[0] + (int)l->x] = ft_color(l->f[0], l->f[1], l->f[2]);
		i++;
	}
	while (l->drawstart < l->drawend)
	{
		l->data[l->drawstart * l->r[0] + (int)l->x] = l->color;
		l->drawstart++;
	}
	i = l->drawend;
	while (i < l->r[1] - 1)
	{
		l->data[i * l->r[0] + (int)l->x] = ft_color(l->c[0], l->c[1], l->c[2]);
		i++;
	}
}

void	colorpick(t_list *l)
{
	char	c;

	c = l->map[l->mapy][l->mapx];
	if (c == '1')
		l->color = 0x00FFFF;
	else if (c == '2')
		l->color = 0x0000FF;
}

void    ft_init_window(t_list *l)
{
	l->rotspeed = 0.025;
	l->movespeed = 0.03;
    l->bpp = 32;
    l->size_line = l->r[0] * 4;
    l->endian = 1;
    l->time = 0;
    l->oldtime = 0;
    l->mlx = mlx_init();
    l->img = mlx_new_image(l->mlx, l->r[0], l->r[1]);
    l->data = (int *)mlx_get_data_addr(l->img, &(l->bpp), &(l->size_line), &(l->endian));
	l->win = mlx_new_window(l->mlx, l->r[0], l->r[1], "Cub3D");
    mlx_loop_hook(l->mlx, draw, l);
	mlx_hook(l->win, 2, 0, vaultmovement, l);
	mlx_hook(l->win, 3, 0, vaultmovementtoggle, l);
	mlx_hook(l->win, 17, 0, close_win, l);
    mlx_loop(l->mlx);
}