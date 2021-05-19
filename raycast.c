/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:42:46 by khee-seo          #+#    #+#             */
/*   Updated: 2021/05/20 05:08:26 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	dir_camera_set(t_player *player, t_ray *ray, int x)
{
	ray->map_x = player->pos_x;
	ray->map_y = player->pos_y;
	ray->camera_x = 2 * x / (double)SCREEN_W - 1;
	ray->raydir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->raydir_y = player->dir_y + player->plane_y * ray->camera_x;
}

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

void	cast(t_player *player, t_ray *ray)
{
	int			x;
	int			hit;

	x = 0;
	while (x <= SCREEN_W)
	{
		hit = 1;
		dir_camera_set(player, ray, x);
		check_step(player, ray);
		while (hit)
		{
			sum_ray(ray);
		//	if (worldmap[ray->map_y][ray->map_x] > 0)
		//		hit = 0;
		}
		x++;
	}
}

int		raycasting(t_window *window)
{
	t_ray ray;

	window->screen = mlx_new_image(window->mlx, SCREEN_W, SCREEN_H);
	window->screen_data = (unsigned int *)mlx_get_data_addr(window->screen,
			&window->bpp, &window->size_line, &window->endian);

	//cast(player, ray);
		
	return (0);
}
