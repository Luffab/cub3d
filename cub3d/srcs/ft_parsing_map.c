/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing_map.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 15:19:10 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 18:07:50 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

char    *ft_putbackline(char *str)
{
    char *s;
    int i;
    int j;

    j = 0;
    i = ft_strlen(str) + 1;
    s = malloc(i * sizeof(char) + 1);
    while (str[j])
    {
        s[j] = str[j];
        j++;
    }
    s[j] = '\n';
    s[j + 1] = '\0';
    return (s);
}


int     ft_check_wall(t_list *l)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (l->map[y][x] != '\0')
    {
        if (l->map[y][x] != '1')
            return (0);
        x++;
    }
    x = 0;
    y = 0;
    while (l->map[y] != 0)
    {
        if (l->map[y][x] != '1')
            return (0);
        y++;
    }
    x = ft_strlen(l->map[x]) - 1;
    y = 0;
   while (l->map[y] != 0)
    {
        if (l->map[y][x] != '1')
            return (0);
        y++;
    }
    x = 0;
    y--;
    while (l->map[y][x] != '\0')
    {
        if (l->map[y][x] != '1')
            return (0);
        x++;
    }
    return (1);
}

int     ft_checkcharinmap(t_list *l)
{
    int x;
    int y;

    y = 0;
    while (l->map[y] != 0)
    {
        x = 0;
        while (l->map[y][x])
        {
            if (l->map[y][x] != '0' && l->map[y][x] != '1' && l->map[y][x] != '2' && l->map[y][x] != 'N' && l->map[y][x] != 'S' && l->map[y][x] != 'W' && l->map[y][x] != 'E')
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

int     ft_checkpos(t_list *l)
{
    int x;
    int y;
	int i;

	y = 0;
	i = 0;
    while (l->map[y] != 0)
    {
        x = 0;
        while (l->map[y][x])
        {
            if (l->map[y][x] == 'N' || l->map[y][x] == 'S' || l->map[y][x] == 'W' || l->map[y][x] == 'E')
                i++;
            x++;
        }
        y++;
    }
	if (i < 1 || i > 1)
    	return (0);
	return (1);
}

int		ft_countnumber(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] == '0' || str[j] == '1' || str[j] == '2' || str[j] == 'N' || str[j] == 'S' || str[j] == 'W' || str[j] == 'E')
			i++;
		j++;
	}
	return (i);
}

int		ft_goodnb(t_list *l)
{
	int x;
    int y;

    y = 0;
    while (l->map[y] != 0)
    {
        x = 0;
        while (l->map[y][x])
        {
            if (ft_countnumber(l->map[0]) != ft_countnumber(l->map[y]))
                return (0);
            x++;
        }
        y++;
	}
    return (1);
}

int		ft_isdoublebackline(t_list *l)
{
	int x;
    int y;

    y = 0;
    while (l->map[y] != 0)
    {
        x = 0;
        while (l->map[y][x])
        {
            if (l->map[y][x] == '\n' && l->map[y + 1][0] == '\n')
                return (0);
            x++;
        }
        y++;
	}
    return (1);
}

int		ft_check_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '2') || str[i] == ' ' || str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			return (1);
		i++;
	}
	return (0);
}

void     ft_get_posdeb(t_list *l)
{
    int x;
    int y;

    y = 0;
    while (l->map[y] != 0)
    {
        x = -1;
        while (l->map[y][++x])
        {
            if (l->map[y][x] == 'N' || l->map[y][x] == 'E' || l->map[y][x] == 'S' || l->map[y][x] == 'W')
            {
                l->posx = x;
                l->posy = y;
                l->map[y][x] = '0';
            }
            if (l->map[y][x] == 'E')
                l->east = 1;
            else if (l->map[y][x] == 'S')
                l->south = 1;
            else if (l->map[y][x] == 'W')
                l->west = 1;
            else if (l->map[y][x] == 'N')
                l->north = 1;
        }
        y++;
    }
}

int     ft_size_mapy(t_list *l)
{
    int y;

    y = 0;
    while (l->map[y] != 0)
        y++;
    return (y);
}