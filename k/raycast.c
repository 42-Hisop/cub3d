/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:42:46 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/29 20:37:01 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_step(t_player *player, t_ray *ray)
{
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

void	sum_ray(t_ray *ray)
{
	if (ray->sidedist_x < ray->sidedist_y)
	{
		ray->sidedist_x += ray->deltadist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->sidedist_y += ray->deltadist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

void	cast(t_window *window, t_ray *ray)
{
	int			x;
	int			hit;

	x = 0;
	while (x <= SCREEN_W)
	{
		hit = 1;
		dir_camera_set(window->player, ray, x);
		check_step(window->player, ray);
		while (hit)
		{
			sum_ray(ray);
			if (window->map[ray->map_y][ray->map_x] == '1')
				hit = 0;
		}
		dist(window->player, ray);
		draw(window, window->texture, ray, x);
		x++;
	}
}

int		raycasting(t_window *window)
{
	t_ray ray;

	window->screen = mlx_new_image(window->mlx, SCREEN_W, SCREEN_H);
	window->screen_data = (unsigned int *)mlx_get_data_addr(window->screen,
			&window->bpp, &window->size_line, &window->endian);
	cast(window, &ray);
	mlx_clear_window(window->mlx, window->win);
	mlx_put_image_to_window(window->mlx, window->win, window->screen, 0, 0);
	mlx_destroy_image(window->mlx, window->screen);
	return (0);
}
