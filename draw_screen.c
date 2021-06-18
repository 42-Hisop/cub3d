/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 21:17:24 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/18 21:44:05 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	draw_fnc(t_window *window, int x)
{
	int		i;

	i = 1;
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
		if (tex_y > texture->height)
			tex_y = texture->height - 1;
		if (tex_y == 0)
			tex_y += 1;
		if (ray->side == 0)
			window->screen_data[(window->size_line / 4) * st_end[0] + st_end[2]]
			   	= texture->img_data[(texture->size_line / 4) * tex_y + ray->tex_x];
		else
			// 위와 같으나 반쯤 어둡게 음영처리 >> 1 & 8355711;
		st_end[0]++;
		temp_y += step;
	}
}

void	draw(t_window *window, t_texture *texture, t_ray *ray, int x)
{
	int		st_end[3];
	double	step;

	st_end[0] = SCREEN_H / 2 - ray->line_height / 2;
	st_end[1] = SCREEN_H / 2 + ray->line_height / 2;
	st_end[2] = x;
	if (st_end[0] < 0)
		st_end[0] = 0;
	if (st_end[1] > SCREEN_H)
		st_end[1] = SCREEN_H;
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = texture->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = texture->width - ray->tex_x - 1;
	//이 부분을 응용하면 텍스처 처리 가능?
	draw_fnc(window, x);
	draw_texture(window, texture, ray, st_end);
}
