#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include <math.h>

typedef struct	s_list
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned int 	color;
	char			*data_color;
    int				r[2];
	int				size_map;
	int				size_mapy;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			**map;
	int				f[3];
	int				c[3];
	int				north;
	int				east;
	int				west;
	int				south;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	int				time;
	int				oldtime;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	long int		img_color;
	int				chan[3];
	int				upkey;
	int				downkey;
	int				leftkey;
	int				rightkey;
	double				olddirx;
	double				oldplanex;
	double			movespeed;
	double			rotspeed;
	int 			x;
}				t_list;

void	cub3d(void);
void	ft_initl(t_list *l);
int		ft_information(t_list *l);
int		ft_putsize(t_list *l, char *str);
int		ft_puttexture(t_list *l, char *str);
int		ft_verify_arg(char *str, t_list *l);
int		ft_putrgbf(t_list *l, char *str);
int		ft_putrgbc(t_list *l, char *str);
int		ft_checkerror(t_list *l);
char    *ft_putintab(char *str, char *map);
int     ft_check_wall(t_list *l);
char    *ft_putbackline(char *str);
int     ft_checkcharinmap(t_list *l);
int     ft_checkpos(t_list *l);
int		ft_goodnb(t_list *l);
int		ft_isdoublebackline(t_list *l);
int		ft_check_line(char *str);
void     ft_get_posdeb(t_list *l);
int     ft_size_mapy(t_list *l);
void	ft_init_window(t_list *l);
void	colorpick(t_list *l);
void			novatempus(t_list *l);
int		repeat(t_list *l);
int		keyhooks(t_list *g);

#endif