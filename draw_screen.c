/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 21:17:24 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/20 04:32:14 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	find_which_wall(t_ray *ray)
{
	//side == 0이면 x축에 박았다는 뜻. 거기에 dirx가 양수면 우측으로 향한다는 뜻

	if (ray->side == 1 && ray->raydir_y < 0) // 이 케이스는 북쪽 y축, 위로 향했으니.
		ray->nswe = 0;
	if (ray->side == 1 && ray->raydir_y > 0) // 남
		ray->nswe = 1;
	if (ray->side == 0 && ray->raydir_x < 0) // 서
		ray->nswe = 2;
	if (ray->side == 0 && ray->raydir_x > 0) // 동
		ray->nswe = 3;
}

void	draw_fnc(t_window *window, int x)
{
	int		i;

	i = 0;
	while (i < SCREEN_H)
	{
		if (i > SCREEN_H)
			i = SCREEN_H;
		if (i > SCREEN_H / 2)
			window->screen_data[(window->size_line / 4) * i + x] = window->c_color;
		else
			window->screen_data[(window->size_line / 4) * i + x] = window->f_color;
		i++;
	}
}

void	draw_texture(t_window *window, t_texture *texture, t_ray *ray, int *st_end)
{
	double		step;
	double		temp_y;
	int			tex_y;

	temp_y = 0;
	step = 1.0 * texture->height / ray->line_height;
	while (st_end[0] <= st_end[1])
	{
		tex_y = temp_y;
//		if (tex_y > texture->height)
//			tex_y = texture->height - 1;
//		if (tex_y == 0)
//			tex_y += 1;
		if (ray->side == 0)
			window->screen_data[(window->size_line / 4) * st_end[0] + st_end[2]]
			   	= texture[ray->nswe].img_data[(texture->size_line / 4) * tex_y + ray->tex_x];
		else // 한쪽 벽 어둡게 처리
			window->screen_data[(window->size_line / 4) * st_end[0] + st_end[2]]
			   	= texture[ray->nswe].img_data[(texture->size_line / 4) * tex_y + ray->tex_x] >> 1 & 8355711;
		st_end[0]++;
		temp_y += step;
	}
}

void	draw(t_window *window, t_texture *texture, t_ray *ray, int x)
{
	int		st_end[3];

	st_end[0] = SCREEN_H / 2 - ray->line_height / 2;
	st_end[1] = SCREEN_H / 2 + ray->line_height / 2;
	st_end[2] = x;
	if (st_end[0] < 0)
		st_end[0] = 0;
	if (st_end[1] > SCREEN_H)
		st_end[1] = SCREEN_H;
	find_which_wall(ray);
	ray->tex_x = ray->hit_point * texture[ray->nswe].width;
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = texture[ray->nswe].width - ray->tex_x;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = texture[ray->nswe].width - ray->tex_x;
	draw_fnc(window, x);
	draw_texture(window, texture, ray, st_end);
}
