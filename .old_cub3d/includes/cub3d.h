/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:50:00 by p          #+#    #+#             */
/*   Updated: 2024/04/24 15:08:38 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <time.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft/libft.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

// Window Size
# define WIN_WIDTH 1000
# define WIN_HEIGHT 600

// raycasting defines
# define FOV 1.0471975512 // (60 * (pi / 180))

# define SPEED_ROTATION 3
# define SPEED_MOVEMENT 4
# define FPS_LIMIT 120

# define MINIMAP_SCALE 6
# define MMAP_OFFSET 10

# define ERR_PRE "\e[1;31mError: "
# define ERR_END "\e[0m\n"

# define UNSET_COLOR UINT32_MAX // used for parsing init value
# define INVALID_COLOR INT32_MAX

# define MAP_NORTH 0
# define MAP_SOUTH 1
# define MAP_EAST  2
# define MAP_WEST  3

# define RED	 "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE	"\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN	"\033[0;36m"
# define BOLD	"\033[1m"
# define RESET   "\033[0m"

# define SPACE ' '
# define X_CROSS  17 // event for closing the mlx windows with the cross button

# define KEY_PRESS 2
# define KEY_RELEASE 3

# define MAP_TEXTURES 10

// ------------------- STRUCTURES DECLARATION -------------------------

/**
 * @brief Kernel assigned numbers to keys
 * 
 */
typedef enum e_keys
{
	KEY_ECHAP = 65307,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_SPACE = 32,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100
}			t_keys;

typedef struct s_point
{
	uint32_t	x;
	uint32_t	y;
}	t_point;

typedef struct s_fps
{
	double	fps;
	double	load;
	int		frame_count;
}	t_fps;

/**
 * @brief mlx variables
 * 
 */
typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	void		*image;
	uint32_t	*image_data;
}	t_mlx;

typedef struct s_player
{
	bool	go_forward;
	bool	go_backward;
	bool	go_left;
	bool	go_right;

	bool	turn_left;
	bool	turn_right;

	double	x;
	double	y;
	double	angle;
}	t_player;

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_font_data
{
	uint32_t	width;
	uint32_t	height;
	uint32_t	charcount;
	uint32_t	charsize;
	uint8_t		*data;
}	t_font_data;

/**
 * @brief main structure
 * 
 */
typedef struct s_map
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	int8_t		player_start_axis;
	int			player_start_x;
	int			player_start_y;
	char		**map;
	size_t		map_width;
	size_t		map_height;
	t_mlx		*mlx;
	t_player	*player_ptr;
	t_texture	*textures[MAP_TEXTURES];
	t_font_data	*font;
}	t_map;

// ------------------- FUNCTIONS PROTOTYPES -------------------------

// tools_1.c
void		*ft_rcalloc(void *ptr, size_t old_size, size_t new_size);
char		*get_line(int fd);
int			t(int a, int b, int c);

// tools_2.c
void		print_usage(void);
double		get_us(void);
double		get_start_angle(char c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isspace(int c);

// tools_3.c
char		*ft_strncpy(char *dest, const char *src, size_t n);
int			get_end_line(char *str);
bool		is_player(char c);

// parsemap.c
void		free_map_struct(t_map *map);
t_map		*parse_map(char *filename, t_map **main_map);
bool		correct_texture_args(char **split);
char		**parse_map_lines(t_map *map, int fd, char *line);

// parsing_close_map.c
void		check_closed_map(t_map *map);

//parsing_tools_1.c
int			is_empty_line(char *line);
int			is_map_line(char *line);
int			char_to_axis(char c);
void		check_texture(char *line, char **orientation);
void		check_if_already_set(t_map *map, char *str, int fd, char *line);

//parsing_tools_2.c
void		parse_map_line_2(char *line, char **result, int fd, t_map *map);
int			does_start_with(const char *line, const char *prefix);
void		check_map_complete(t_map *map);
int			parse_color_component(char **str);
uint32_t	parse_color(char *str);

//parsing_tools_3.c
int			parse_textures(char *line, t_map *map, int fd);
int			parse_textures_2(char *line, t_map *map, int fd);
int			parse_textures_3(char *line, t_map *map, int fd);
bool		is_safe_step_ok(char **map, int i, int j);
void		parse_first_last_line(char *real_map, t_map *map);

// security_functions.c
bool		incorrect_window_size(void);
void		*secure_malloc(size_t size);
void		custom_exit(t_map *map, char *str);
void		error_message(char *optionnal_message);

// init_struct.c
t_map		*alloc_map_struct(void);
void		init_mlx(t_map **foo);

// free_functions.c
void		free_map_struct(t_map *map);
void		free_split(char **to_free);
void		failed_window(t_map *map);
void		failed_image(t_map *map);
int			free_cross(t_map **foo);

// mlx_hook.c
int			handle_keyboard_down(int key_code, t_map **foo);
int			handle_keyboard_up(int key_code, t_map **foo);

// cub3d.c
void		cub3d(t_map **foo);
double		stabilize_fps(double *load);

// debug_tools.c
void		print_map(t_map *map);

// texture.c
void		texture_free(void *mlx, t_texture *texture);
void		texture_append(t_map *map, char *path, int index);
void		texture_loadall(t_map *map);

// font.c
t_font_data	*font_load(char *file);
void		font_free(t_font_data *psf);
void		font_draw(t_map *map, uint32_t xo, uint32_t yo, uint8_t c);
void		font_print(t_map *map, uint32_t x, uint32_t y, char *str);

// minimap.c
void		draw_fps(t_map *map, double new_fps, double new_load);
void		draw_shadow_box(t_map *map, t_point start, t_point end);
void		minimap(t_map *map);
void		draw_rect(t_map *map, t_point start, t_point end, uint32_t color);

// raycasting.c
void		raycasting(t_map *restrict map, t_player *restrict player);

#endif
