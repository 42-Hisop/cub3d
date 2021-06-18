/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 21:17:24 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/18 04:10:10 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	draw(t_window *window, t_texture *texture, t_ray *ray, int x)
{
	int		draw_st;
	int		draw_end;
	double	step;

	draw_st = SCREEN_H / 2 - ray->line_height / 2;
	draw_end = SCREEN_H / 2 + ray->line_height / 2;
	if (draw_st < 0)
		draw_st = 0;
	if (draw_end > SCREEN_H)
		draw_end = SCREEN_H;
	step = 1.0 * texture->height / ray->line_height;
}
