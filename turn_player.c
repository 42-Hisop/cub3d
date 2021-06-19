/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 04:49:13 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/20 05:16:05 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	turn_left(t_player *player)
{
	double		temp_x;
	double		temp_y;
	double		temp_px;
	double		temp_py;
	double		seta;
	
	temp_x = player->dir_x;
	temp_y = player->dir_y;
	temp_px = player->plane_x;
	temp_py = player->plane_y;
	seta =  (M_PI / 180) * 10;
	player->dir_x = temp_x * cos(seta) - temp_y * sin(seta);
	player->dir_y = temp_x * sin(seta) + temp_y * cos(seta);
	player->plane_x = temp_px * cos(seta) - temp_py * sin(seta);
	player->plane_y = temp_px * sin(seta) + temp_py * cos(seta);
}

void	turn_right(t_player *player)
{
	double		temp_x;
	double		temp_y;
	double		temp_px;
	double		temp_py;
	double		seta;
	
	temp_x = player->dir_x;
	temp_y = player->dir_y;
	temp_px = player->plane_x;
	temp_py = player->plane_y;
	seta =  (M_PI / 180) * 10;
	player->dir_x = temp_x * cos(-seta) - temp_y * sin(-seta);
	player->dir_y = temp_x * sin(-seta) + temp_y * cos(-seta);
	player->plane_x = temp_px * cos(-seta) - temp_py * sin(-seta);
	player->plane_y = temp_px * sin(-seta) + temp_py * cos(-seta);
}
