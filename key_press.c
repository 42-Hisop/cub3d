/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 04:33:24 by khee-seo          #+#    #+#             */
/*   Updated: 2022/02/18 12:27:35 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 이동할 때 검사하고 이동하자. temp 만들어 현재위치 저장, 더해서 유효한지 확인후 이동. 인자로 map을 받아와서 유효한지 검사해야함.

void	move_forward(t_player *player)
{
	player->pos_x += player->dir_x * 0.2;
	player->pos_y += player->dir_y * 0.2;
}

void	move_backward(t_player *player)
{
	player->pos_x -= player->dir_x * 0.2;
	player->pos_y -= player->dir_y * 0.2;
}

void	move_left(t_player *player)
{
	double		temp_x;
	double		temp_y;
	double		seta;

	temp_x = player->dir_x;
	temp_y = player->dir_y;
	seta = (M_PI / 180) * 90;
	player->pos_x += (temp_x * cos(-seta) - temp_y * sin(-seta)) * 0.2;
	player->pos_y += (temp_x * sin(-seta) + temp_y * cos(-seta)) * 0.2;
}

void	move_right(t_player *player)
{
	double		temp_x;
	double		temp_y;
	double		seta;

	temp_x = player->dir_x;
	temp_y = player->dir_y;
	seta = (M_PI / 180) * 90;
	player->pos_x += (temp_x * cos(seta) - temp_y * sin(seta)) * 0.2;
	player->pos_y += (temp_x * sin(seta) + temp_y * cos(seta)) * 0.2;
}

int		key_press(int key, t_window *window)
{
	if (key == 13)
		move_forward(window->player);
	if (key == 1)
		move_backward(window->player);
	if (key == 0)
		move_left(window->player);
	if (key == 2)
		move_right(window->player);
	if (key == 123)
		turn_left(window->player);
	if (key == 124)
		turn_right(window->player);
	if (key == 53)
		exit(0);
	return (0);
}
