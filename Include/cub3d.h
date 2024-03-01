/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:12:23 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/01 04:08:47 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../Lib/includes/lib.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <X11/Xlib.h>

# define H 720
# define W 960
# define SPEED 0.5
# define T_SIZE 64
# define PI 3.1415926535
# define TURN_ANGLE 32
# define FOV_ANGLE 60
# define MMSF 0.1
# define TEXTURE_SIZE 64
# define EXIT_SUCCESS 0
# define EXIT_FAIL 1
# define MOUSE_SPEED 8000
# define COUNT_WEST_XPM 12
# define ANIMATION_SPEED 1855000

# define PORTE "./textures/porte.xpm"

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		ll;
	int		end;
	int		h;
	int		w;
}				t_img;

typedef struct s_raystock
{
	double	x;
	double	y;
}				t_raystock;

typedef struct s_utils
{
	char		**input;
	int			fd;
	char		**elem;
	char		**map;
	int			max_len;
	int			max_height;
	int			fl_map;
	void		*mlx_ptr;
	t_raystock	rays[W];
}				t_utils;

typedef struct s_elem
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		colors_f[3];
	int		colors_c[3];
	char	**split_color_f;
	char	**split_color_c;
}				t_elem;

typedef struct s_mlx
{
	void	*ptr;
	void	*win_ptr;
}				t_mlx;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	int		color;
}				t_player;

typedef struct s_ray
{
	double	x;
	double	y;
	double	wallhit_x;
	double	wallhit_y;
	double	distance;
	int		isfacingd;
	int		isfacingr;
	int		texx;
	int		texy;
	int		hithv;
	double	step;
	double	texpos;
	int		color;
	double	xintercept;
	double	yintercept;
}			t_ray;

typedef struct s_wall
{
	double	height;
	double	top;
	double	bottom;
	double	porte;
	int		open;
}				t_wall;

typedef struct s_memory
{
	void			*add;
	struct s_memory	*next;
}				t_memory;

typedef struct s_data
{
	t_mlx		mlx;
	t_img		img;
	t_img		textures[5];
	t_img		west_textures[COUNT_WEST_XPM];
	t_img		east_textures[COUNT_WEST_XPM];
	t_img		north_textures[COUNT_WEST_XPM];
	t_img		south_textures[COUNT_WEST_XPM];
	t_utils		utils;
	t_elem		elem;
	t_player	player;
	t_ray		ray;
	t_wall		wall;
	t_memory	*mem;
	int			frame;
}				t_data;

//////// PARSE ////////
void			check_args(t_data *data, int ac, char **av);
void			parse_map(t_data *data, char **map);
int				check_char(char **map);
int				check_player(char **map);
int				check_closed(char **map);

//////// UTILS ////////
int				is_player(char c);
int				is_cub(char *str);
int				is_header(t_data *data, char *line);
int				coma_count(char *str);
double			ft_atan2(double y, double x);
double			to_rad(double angle);
int				check_for_nl(char *str);
void			check_after_nl(t_data *data, int j);
char			*ft_strdup_no_space(t_data *data, char *s1);

///////// GET /////////
/*  check_images_exist.c */
void			check_images_exist(t_data *data);
char			*get_xpm_filename(int i);
void			get_input(t_data *data, char **av);
int				nb_fileline(t_data *data, char **av);
int				get_elem(t_data *data);
void			init_elem(t_data *data);
void			ft_get_elem(t_data *data, char *line);
void			get_no_path(t_data *data, char *str);
void			get_so_path(t_data *data, char *str);
void			get_ea_path(t_data *data, char *str);
void			get_we_path(t_data *data, char *str);
void			get_c_colors(t_data *data, char *str);
void			get_f_colors(t_data *data, char *str);
void			get_map(t_data *data, int fl_map);
void			get_map2(t_data *data, int k, int i, int fl_map);
char			*fill_spaces(t_data *data, int max_len);
char			*complete_spaces(t_data *data, int fl_map);
void			get_player_pos(t_data *data);
void			get_dir(t_data *data, char c);

///////// MLX //////////
void			init_mlx(t_data *data);
void			init_mlx2(t_data *data);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

//////// DRAW //////////
/// GAME ///
int				draw_game(t_data *data);
void			stock_ray(t_data *data, double x, double y, int i);
void			draw_the_rest(t_data *data);

/*  ray_utils.c  */
void			ray_orientation(t_data *data);
void			ray_rotate(t_data *data);

/*  game_init.c  */
void			init(t_data *data);

/*  fix_fisheye.c  */
double			fix_fisheye(t_data *data, double ray_angle, double dir_angle);

/*  load_texture.c  */
void			update_frame(t_data *data);
void			load_west_textures(t_data *data, int i);
void			load_east_textures(t_data *data, int i);
void			load_north_textures(t_data *data, int i);
void			load_south_textures(t_data *data, int i);

/// SKYGROUND ///
void			draw_skyground(t_data *data);
int				get_color(int r, int g, int b);
/// DDA ///
void			horizontal_hit(t_data *data, double ray_angle);
void			find_hor_hit(t_data *data, double xstep, double ystep);
void			vertical_hit(t_data *data, double ray_angle);
void			find_ver_hit(t_data *data, double xstep, double ystep);

/*  dda_utils.c  */
bool			is_new_hit_distance_smaller(t_data *data);
bool			is_ray_in_limits(const t_data *data);
void			update_hor_hit(t_data *data);
int				is_wallh(t_data *data, double x, double y);
int				is_wallv(t_data *data, double x, double y);

/// WALL ///
void			texture_hit_x(t_data *data);
void			draw_strip(t_data *data, int i);
void			draw_texture(t_data *data, int y, int i);
void			draw_text(t_data *data, t_img *imgtext, int x, int y);
unsigned int	get_text_color(void *img, int x, int y);
/// MINIMAP ///
void			draw_minimap(t_data *data, char **map);
void			draw_wall(t_data *data, int x, int y);
void			draw_floor(t_data *data, int x, int y);
/// PLAYER ///
void			draw_player(t_data *data, double x, double y, int radius);
void			draw_ray(t_data *data);
void			draw_each_ray(t_data *data, double x1, double y1, int j);
///////// KEY //////////
int				ft_key(int key, t_data *data);
void			move_front(t_data *data);
void			move_back(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
void			rotate_right(t_data *data);
void			rotate_left(t_data *data);
int				handle_mouse_move(int x, int y, void *param);

///////// FREE /////////
void			add_in_list(t_data *data, void *add);
void			*ft_malloc(t_data *data, size_t size);
int				ft_exit(t_data *data, char *msg_err, int exitcode);
void			free_text(t_data *data);
void			ft_free_all(t_data *data);
void			free_garcol(t_data *data);
int				ft_end(t_data *data);

#endif