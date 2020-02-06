/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing_arg.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 13:08:33 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 02:48:04 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_verify_arg(char *str, t_list *l)
{
	int i;

	i = 0;
	while (str[i] == ' ' && str[i])
		i++;
	if (ft_strncmp(str + i, "NO ", 3) == 0 || ft_strncmp(str + i, "SO ", 3) == 0 ||
		ft_strncmp(str + i, "WE ", 3) == 0 || ft_strncmp(str + i, "EA ", 3) == 0 ||
		ft_strncmp(str + i , "R ", 2) == 0 || ft_strncmp(str + i, "S ", 2) == 0 ||
		ft_strncmp(str + i, "F ", 2) == 0 || ft_strncmp(str + i, "C ", 2) == 0)
		return (1);
	else if ((ft_strncmp(str + i, "1", 1) == 0 || ft_strncmp(str + i, "0", 1) == 0) && l->c[0] > -1 && l->ea && l->f[0] > -1 && l->no && l->r[0] > -1 && l->s && l->so && l->we)
		return (1);
	return (0);
}

int		ft_count_arg(char *str, char c)
{
	int i;
	int j;

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

int	ft_puttexture(t_list *l, char *str)
{
	int i;

	i = 0;
	if (str && (ft_strnstr(str, "NO", ft_strlen(str)) || ft_strnstr(str, "SO", ft_strlen(str))
		|| ft_strnstr(str, "WE", ft_strlen(str)) || ft_strnstr(str, "S", ft_strlen(str))
		|| ft_strnstr(str, "EA", ft_strlen(str))))
	{
		while (str[i] != '.' && str[i])
			i++;
		if (ft_verify_arg(str, l) && ft_strnstr(str, "NO", ft_strlen(str)))
			l->no = ft_strdup(str + i);
		else if (ft_verify_arg(str, l) && ft_strnstr(str, "SO", ft_strlen(str)))
			l->so = ft_strdup(str + i);
		else if (ft_verify_arg(str, l) && ft_strnstr(str, "WE", ft_strlen(str)))
			l->we = ft_strdup(str + i);
		else if (ft_verify_arg(str, l) && ft_strnstr(str, "EA", ft_strlen(str)))
			l->ea = ft_strdup(str + i);
		else if (ft_verify_arg(str, l) && ft_strnstr(str, "S", ft_strlen(str)))
			l->s = ft_strdup(str + i);
		else
			return (0);
	}
	else if (*str && !ft_verify_arg(str, l))
		return (0);
	return (1);
}

int	ft_putsize(t_list *l, char *str)
{
	int i;

	i = 0;
	if (str && ft_strnstr(str, "R", ft_strlen(str)))
	{
		while ((str[i] < '0' || str[i] > '9') && str[i])
			i++;
		if (ft_verify_arg(str, l) && ft_count_arg(str + i, ' ') == 1)
		{
			if (str[i - 1] == '-')
				i--;
			l->r[0] = ft_atoi(str + i);
			while (str[i] != ' ' && str[i])
				i++;
			while (str[i] == ' ' && str[i])
				i++;
			l->r[1] = ft_atoi(str + i);
		}
		else
			return (0);
		return (1);
	}
	return (1);
}

int	ft_putrgbf(t_list *l, char *str)
{
	int i;

	i = 0;
	if (str && ft_strnstr(str, "F", ft_strlen(str)))
	{
		while (str[i] != 'F' && str[i])
			i++;
		i++;
		while ((str[i] == ' ') && str[i])
			i++;
		if (ft_verify_arg(str, l) && ft_count_arg(str, ',') == 2)
		{
			if (str[i - 1] == '-')
				i--;
			l->f[0] = ft_atoi(str + i);
			while (str[i] != ' ' && str[i] != ',')
				i++;
			while (str[i] == ' ' || str[i] == ',')
				i++;
			l->f[1] = ft_atoi(str + i);
			while (str[i] != ' ' && str[i] != ',')
				i++;
			while (str[i] == ' ' || str[i] == ',')
				i++;
			l->f[2] = ft_atoi(str + i);
			if (str[i] == '-')
				i++;
			while (str[i] != '\0')
			{
				if ((str[i] < '0' || str[i]> '9'))
					return (0);
				i++;
			}
		}
		else
			return (0);
	}
	return (1);
}

int	ft_putrgbc(t_list *l, char *str)
{
	int i;

	i = 0;
	if (str && ft_strnstr(str, "C", ft_strlen(str)))
	{
		while (str[i] != 'C' && str[i])
			i++;
		i++;
		while ((str[i] == ' ') && str[i])
			i++;
		if (ft_verify_arg(str, l) && ft_count_arg(str, ',') == 2)
		{
			if (str[i - 1] == '-')
				i--;
			l->c[0] = ft_atoi(str + i);
			while (str[i] != ' ' && str[i] != ',')
				i++;
			while (str[i] == ' ' || str[i] == ',')
				i++;
			l->c[1] = ft_atoi(str + i);
			while (str[i] != ' ' && str[i] != ',')
				i++;
			while (str[i] == ' ' || str[i] == ',')
				i++;
			l->c[2] = ft_atoi(str + i);
			if (str[i] == '-')
				i++;
			while (str[i] != '\0')
			{
				if ((str[i] < '0' || str[i] > '9'))
					return (0);
				i++;
			}
		}
		else
			return (0);
	}
	return (1);
}

int	ft_information(t_list *l)
{
	int 	ret;
	char	*line;
	int		fd;
	char 	*s;

	s = ft_strdup("");
	if (!(fd = open("map.cub", O_RDONLY)))
		return (0);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			return (0);
		if (*s && !ft_check_line(line) && l->c[0] > -1 && l->ea && l->f[0] > -1 && l->no && l->r[0] > -1 && l->s && l->so && l->we)
			return (0);
		if (ft_verify_arg(line, l) && l->c[0] > -1 && l->ea && l->f[0] > -1 && l->no && l->r[0] > -1 && l->s && l->so && l->we)
		{
			line = ft_putbackline(line);
			s = ft_strjoin(s, line);
		}
		if (ft_verify_arg(line, l) && l->c[0] > -1 && l->ea && l->f[0] > -1 && l->no && l->r[0] > -1 && l->s && l->so && l->we && *line == '\n')
			return (0);
		if (!ft_puttexture(l, line))
			return (0);
		if (!ft_putsize(l, line))
			return (0);
		if (!ft_putrgbc(l, line))
			return (0);
		if (!ft_putrgbf(l, line))
			return (0);
	}
	l->map = ft_split(s, '\n');
	l->size_mapy = ft_size_mapy(l);
	l->size_map = ft_strlen(l->map[0]);
	if (!ft_check_wall(l) || !ft_checkcharinmap(l) || !ft_checkpos(l) || !ft_goodnb(l) || !ft_isdoublebackline(l))
		return (0);
	ft_get_posdeb(l);
	return (1);
}

int		ft_checkerror(t_list *l)
{		
	if (!ft_information(l) || !l->s || !l->no || !l->so || !l->ea || !l->we)
	{
		ft_putstr_fd("Error\nDATA_ERROR", 1);
		return (0);
	}
	if (l->r[0] > 2560 || l->r[1] > 1440)
	{
		if (l->r[0] > 2560)
			l->r[0] = 2560;
		if (l->r[1] > 1440)
			l->r[1] = 1440;
	}
	if (l->r[0] < 0 || l->r[1] < 0)
	{
		ft_putstr_fd("Error\nRESOLUTION_ERROR", 1);
		return (0);
	}
	if ((l->f[0] > 255 || l->f[1] > 255 || l->f[2] > 255) || (l->f[0] < 0 || l->f[1] < 0 || l->f[2] < 0))
	{
		ft_putstr_fd("Error\nRGB_ERROR", 1);
		return (0);
	}
	if ((l->c[0] > 255 || l->c[1] > 255 || l->c[2] > 255) || (l->c[0] < 0 || l->c[1] < 0 || l->c[2] < 0))
	{
		ft_putstr_fd("Error\nRGB_ERROR", 1);
		return (0);
	}
	return (1);
}