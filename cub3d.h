/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:16:00 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/27 22:44:01 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SCREEN_W 800
# define SCREEN_H 600

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
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
}					t_window;

void				check_map(t_window *window, char *map_name);
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
void				cast(t_window *window, t_ray *ray);
void				cast2(t_window *window, t_ray *ray);
void				dir_camera_set(t_player *player, t_ray *ray, int x);
void				dist(t_player *player, t_ray *ray);
void				draw(t_window *window, t_texture *texture,
		t_ray *ray, int x);
int					key_press(int key, t_window *window);
void				turn_left(t_player *player);
void				turn_right(t_player *player);
int					ft_strcmp(char *s1, char *s2);

int					ft_strlen(char const *s);
char				*ft_strdup(char *src);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strstr(char *rd, char c);
char				*check_m(char *rd, int rd_i, char *backup, char c);
char				**ft_split(char *rd, char c, int i, int rd_i);
char				*save(char *rd, char *buf);
char				**split_line(int fd);

char				**cut_map(char **line);
void				map_valid(char **map);
void				texture_init(t_window *window, t_texture *texture);
t_window			*fnc_color(char **line, t_window *window);

#endif
