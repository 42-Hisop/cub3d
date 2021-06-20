/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:16:00 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/20 21:22:32 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// 지금은 임의로 지정해주었지만 맵 파싱해서 가져와야할 부분...
# define MAP_W 24
# define MAP_H 24
# define SCREEN_W 800
# define SCREEN_H 600

# include "split.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

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
}					t_window;

void				check_map(t_window *window);
void				player_init(char **map, t_player *player);
int					raycasting(t_window *window);
void				*error(void);
int					ft_atoi(char *s);
void				make_hex(char *hex);
char				*ft_itoh(int num, char *rgb, int i);
int					itorgb(int r, int g, int b);
t_texture			*tex_adr(char **line, t_texture *tex);
int					line_format(char *line, char *str);
void				free_line(char **line);
void				check_map(t_window *window);
void				cast(t_window *window, t_ray *ray);
void				cast2(t_window *window, t_ray *ray);
void				dir_camera_set(t_player *player, t_ray *ray, int x);
void				dist(t_player *player, t_ray *ray);
void				draw(t_window *window, t_texture *texture, t_ray *ray, int x);
int					key_press(int key, t_window *window);
void				turn_left(t_player *player);
void				turn_right(t_player *player);

#endif
