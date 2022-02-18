/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:16:00 by khee-seo          #+#    #+#             */
/*   Updated: 2022/02/17 14:20:01 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SCREEN_W 1600
# define SCREEN_H 1200

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // 나중에 빼
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"

typedef struct		s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct		s_texture
{
	char			*adr;
	void			*img;
	unsigned int	*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_texture;

typedef struct		s_ray
{
	double			raydir_x;
	double			raydir_y;
	double			sidedist_x;
	double			sidedist_y;
	double			camera_x;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	double			hit_point;
	int				step_x;
	int				step_y;
	int				side;
	int				tex_x;
	int				line_height;
	int				map_x;
	int				map_y;
	int				nswe;
}					t_ray;

typedef struct		s_window
{
	void			*mlx;
	void			*win;
	void			*screen;
	unsigned int	*screen_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				f_color;
	int				c_color;
	t_player		*player;
	t_texture		*texture;
	char			**map;
	int				line_n;
}					t_window;

int					destroy_notify(t_window *window);
char				*param_main(int argc, char **argv);

int					map_is_last(char *str);
void				skip_space_after_map(char **line, t_window *window);
void				fnc_allocate(char **f, char **c, t_window *window);
t_window			*fnc_color(char **line, t_window *window);

int					check_map_w(char **line, t_window *window);
int					check_map_h(char **line, t_window *window);
char				*dup_map(char *map, char *line, int map_w);
char				**cut_map(char **line, t_window *window);

int					validinwall(char c);
int					wallcheck_w(char **map);
int					wallcheck_h(char **map);
int					validcheck(char **map);
void				map_valid(char **map);

void				vector_init2(char c, t_player *player);
void				vector_init(char c, t_player *player);
void				player_init(char **map, t_player *player, int count);

int					ft_strlen(char const *s);
char				*ft_strdup(char *src);
char				*ft_strjoin(char const *s1, char const *s2);
unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size);
//int					ft_strstr(char *rd, char c);

//char				*check_m(char *rd, int rd_i, char *backup, char c);
char				**ft_split(char *s, char c);
char				*save(char *rd, char *buf);
char				**split_line(int fd);

int					line_format(char *line, char *str);
int					tex_adr_allocate(char **line, t_texture *tex,
		t_window *window, int i);
t_texture			*tex_adr(char **line, t_texture *tex, t_window *window);
void				check_map(t_window *window, char *map_name);

void				texture_init(t_window *window, t_texture *texture);

void				check_step(t_player *player, t_ray *ray);
void				sum_ray(t_ray *ray);
void				cast(t_window *window, t_ray *ray);
int					raycasting(t_window *window);

void				dist(t_player *player, t_ray *ray);
void				dir_camera_set(t_player *player, t_ray *ray, int x);

void				*error(char *str);
int					ft_atoi(char *s);
int					itorgb(int r, int g, int b);
int					ft_strcmp(char *s1, char *s2);
void				free_line(char **line);

void				find_which_wall(t_ray *ray);
void				draw_fnc(t_window *window, int x);
void				draw_texture(t_window *window, t_texture *texture,
		t_ray *ray, int *st_end);
void				draw(t_window *window, t_texture *texture,
		t_ray *ray, int x);

void				move_forward(t_player *player);
void				move_backward(t_player *player);
void				move_left(t_player *player);
void				move_right(t_player *player);
int					key_press(int key, t_window *window);

void				turn_left(t_player *player);
void				turn_right(t_player *player);
#endif
