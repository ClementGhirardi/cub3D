/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 11:40:12 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/20 13:26:36 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <../minilibx-linux/mlx.h>
# include <fcntl.h>
# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define KEY_ESC 65307

# define KEY_Z 122
# define KEY_W 119

# define KEY_S 115

# define KEY_A 97
# define KEY_Q 113

# define KEY_D 100

# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define MOVE_SPEED 0.04
# define COLLISION_RADIUS 0.15
# define ROT_SPEED 0.025

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_texture
{
	char	*path;
	t_img	img;
}	t_texture;

typedef struct s_config
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	int			floor_color;
	int			ceiling_color;
}	t_config;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_keys
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	rot_left;
	int	rot_right;
}	t_keys;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		count;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	frame;
}	t_mlx;

typedef struct s_data
{
	t_config	config;
	t_map		map;
	t_keys		keys;
	t_player	player;
	t_mlx		mlx;
}	t_data;

/*-- Initialization --*/

//			IN
void		init_img(t_img *img);
void		init_config(t_data *data);
void		init_map(t_data *data);
void		init_keys(t_data *data);
void		init_player(t_data *data);
void		init_mlx(t_data *data);

//			EXT
void		init_data(t_data *data);
//--------------------------------//

/*-- Cleanup --*/

//			IN
void		destroy_mlx(t_data *data);
void		free_config(t_config *config);
void		free_map(t_map *map);

//			EXT
void		free_data(t_data *data);
//--------------------------------//

/*-- Parsing --*/

//			IN
typedef enum e_line_type
{
	LINE_EMPTY,
	LINE_NO,
	LINE_SO,
	LINE_WE,
	LINE_EA,
	LINE_F,
	LINE_C,
	LINE_MAP,
	LINE_INVALID
}	t_line_type;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_parse
{
	char	**lines;
	int		line_count;
	int		map_start;
}	t_parse;

int			is_space(char c);
char		*shift_str(char *str, int n);
int			is_player_char(char c);

t_line_type	get_line_type(char *line);

int			read_file_lines(char *filename, t_parse *parse);

int			parse_texture(t_data *data, char *line, t_line_type type);
int			parse_color(t_data *data, char *line, t_line_type type);
int			parse_config(t_data *data, t_parse *parse);

int			extract_map(t_data *data, t_parse *parse);

int			validate_map_chars(t_data *data);
int			validate_map_closed(t_data *data);
int			validate_map(t_data *data);

//			EXT
int			parse_file(t_data *data, char *filename);
//-------------------------------------------------//

/*-- MLX --*/

//			EXT
int			init_mlx_window(t_data *data);

int			init_frame(t_data *data);

int			load_textures(t_data *data);

void		put_pixel(t_img *img, int x, int y, int color);

int			get_pixel(t_img *img, int x, int y);
//--------------------------------------------//

/*-- Player --*/

//			IN
int			can_move_to(t_data *data, double x, double y);

//			EXT
void		move_player(t_data *data, double direction);

void		strafe_player(t_data *data, double direction);

void		rotate_player(t_data *data, double angle);
//--------------------------------------------------//

/*-- Hooks --*/

//			IN
int			close_game(t_data *data);
int			key_press(int keycode, t_data *data);
int			key_release(int keycode, t_data *data);

//			EXT
void		init_hooks(t_data *data);
//---------------------------------//

/* Ray Casting */

//			IN
typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		step_x;
	int		step_y;
	int		side;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
}	t_ray;

void		init_ray(t_data *data, t_ray *ray, int x);
void		init_delta(t_ray *ray);
void		init_step_side(t_data *data, t_ray *ray);
void		perform_dda(t_data *data, t_ray *ray);

//			EXT
void		cast_ray(t_data *data, t_ray *ray, int x);

void		render_frame(t_data *data);
//-----------------------------------//

/*-- Error --*/
//			EXT
int			error_msg(char *message);
//---------------------------------//

#endif
