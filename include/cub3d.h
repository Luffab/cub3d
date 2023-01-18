#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <math.h>

typedef struct s_cast
{
	int				r[2];
	int				f[3];
	int				c[3];
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			*sprite;
	char			**map;
	char			**file;
	char			*data;
	char			face;
	void			*mlx;
	void			*win;
	void			*img;
	double			*zbuffer;
	double			rotspeed;
	double			movespeed;
	double			oldplanex;
	float			posx;
	float			posy;
	double			olddirx;
	double			olddiry;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	double			camerax;
	double			cameray;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			wallx;
	double			step;
	double			texpos;
	float			fov;
	float			**sprite_pos;
	float			transform[2];
	int				count_path;
	int				sprite_start_end[2][2];
	int				sprite_size;
	int				sprite_screen_x;
	int				**buffer;
	int				walkdirection;
	int				turndirection;
	int				east;
	int				north;
	int				south;
	int				west;
	int				**teast;
	int				**tnorth;
	int				**tsouth;
	int				**twest;
	int				**tsprite;
	int				*timg;
	int				bpp;
	int				endian;
	int				size_line;
	int				keyup;
	int				screenheight;
	int				color;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				textnum;
	int				texx;
	int				texy;
	int				texwidth;
	int				texheight;
	int				spritesize;
	int				width;
	int				height;
	unsigned int	bytes_count;
	int				width_in_bytes;
	unsigned int	image_size;
	unsigned int	bytes_size;
	unsigned int	bfoffbits;
	unsigned int	file_size;
	unsigned int	biplanes;
	unsigned char	header[54];
	int				fd;
}				t_cast;

int		ft_check_space_before_path(t_cast *c);
int		ft_count_arg(char *str, char c);
void	ft_path_texture(char *str, t_cast *c);
void	ft_path_texture2(char *str, t_cast *c);
void	ft_get_resolution(char *str, t_cast *c);
void	ft_get_rgb_c(char *str, t_cast *c);
void	ft_get_rgb_f(char *str, t_cast *c);
int		ft_check_map(t_cast *c, char num);
int		ft_check_char(t_cast *c);
int		ft_check_nb_pos(t_cast *c);
void	ft_get_init_pos(t_cast *c);
void	ft_get_init_orientation(t_cast *c);
int		ft_open_file(char *file);
char	*ft_putbackline(char *str);
int		ft_stock_file(t_cast *c, char *file);
void	ft_separate_map(t_cast *c);
int		ft_ready_for_raycast(t_cast *c, char *file);
int		ft_len_of_map(char **str);
void	ft_init_window(t_cast *c);
void	ft_move_player(t_cast *c);
void	ft_floor_casting_loop(t_cast *c);
void	ft_calculate_step(t_cast *c);
void	ft_side_hit(t_cast *c);
void	ft_calculate_pixel_wallx(t_cast *c);
void	ft_put_texture(t_cast *c, int y);
int		ft_render_cast(t_cast *c);
int		ft_rgbtoi(int r, int g, int b);
int		**ft_picture(char *data, int *tab);
int		ft_wall_casting(t_cast *c, double **buffer);
void	ft_ceiling_rgb(t_cast *c, int x);
void	ft_floor_rgb(t_cast *c, int x);
void	ft_walls_rgb(t_cast *c, int x);
void	ft_rotate_player(t_cast *c);
void	ft_walls_textures(t_cast *c, int x);
int		**ft_get_good_texture(t_cast *c);
int		ft_init_texture(t_cast *c);
void	ft_pixel_to_image(t_cast *c, int x, int y, int rgb);
void	ft_sort_list(float **list);
void	ft_force_zero(t_cast *c);
float	**ft_add_sprite(t_cast *c);
void	ft_screen_sprite(t_cast *c, double *buffer);
char	**ft_free_ftab(float **tab);
void	ft_rotate_camera_left(t_cast *c);
void	ft_rotate_camera_right(t_cast *c);
void	ft_is_ns(t_cast *c, char pos);
void	ft_is_ew(t_cast *c, char pos);
void	ft_side(t_cast *c);
void	ft_cub_save_bmp(t_cast *c);
void	ft_render_bmp(t_cast *c);
int		ft_ready_for_bmp(t_cast *c, char *file);
int		ft_good_bmp_name(char *s);
void	ft_free_params(char **file);
int		ft_check_map_norme_x0(t_cast *c, int x, int y, char num);
int		ft_check_map_norme_x1(t_cast *c, int x, int y, char num);
int		ft_close_win(void);
int		ft_char_count(char *s, char num);
void	ft_verify_char(t_cast *c, char *s, char num, int which);
void	ft_free_variable(t_cast *c);
void	ft_free_int_params(int **file);
void	ft_path_texture3(char *str, t_cast *c);
int		ft_in_main(t_cast *c, int ac, char **av);
int		ft_valide_arg(char *str);
int		ft_verify_arg2(t_cast *c);
#endif