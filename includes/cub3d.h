/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:16:00 by khee-seo          #+#    #+#             */
/*   Updated: 2021/05/20 03:18:46 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MAP_W 24
# define MAP_H 24
# define SCREEN_W 800
# define SCREEN_H 600
# include "../mlx/mlx.h"
# include <stdio.h>
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
	t_player		*player;
	t_texture		*texture;
}					t_window;

void				check_map(t_player *player, t_texture *texture);
void				player_init(t_player *player);
int					raycasting(t_window *window);

#endif
