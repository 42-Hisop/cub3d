/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 04:33:24 by khee-seo          #+#    #+#             */
/*   Updated: 2022/02/20 12:42:40 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_player *player, char **map)
{
	int	check_x;
	int	check_y;

	check_x = (int)((player->pos_x + player->dir_x * 1.2));
	check_y = (int)((player->pos_y + player->dir_y * 1.2));
	if (map[check_y][check_x] == '1')
		return ;
	player->pos_x += player->dir_x * 0.2;
	player->pos_y += player->dir_y * 0.2;
}

void	move_backward(t_player *player, char **map)
{
	int	check_x;
	int	check_y;

	check_x = (int)((player->pos_x - player->dir_x * 1.2));
	check_y = (int)((player->pos_y - player->dir_y * 1.2));
	if (map[check_y][check_x] == '1')
		return ;
	player->pos_x -= player->dir_x * 0.2;
	player->pos_y -= player->dir_y * 0.2;
}

void	move_left(t_player *player, char **map)
{
	int		check_x;
	int		check_y;
	double	seta;

	seta = (M_PI / 180) * 90;
	check_x = (int)((player->pos_x + (player->dir_x * cos(-seta)
					- player->dir_y * sin(-seta)) * 1.2));
	check_y = (int)((player->pos_y + (player->dir_x * sin(-seta)
					+ player->dir_y * cos(-seta)) * 1.2));
	if (map[check_y][check_x] == '1')
		return ;
	player->pos_x += (player->dir_x * cos(-seta)
			- player->dir_y * sin(-seta)) * 0.2;
	player->pos_y += (player->dir_x * sin(-seta)
			+ player->dir_y * cos(-seta)) * 0.2;
}

void	move_right(t_player *player, char **map)
{
	int		check_x;
	int		check_y;
	double	seta;

	seta = (M_PI / 180) * 90;
	check_x = (int)((player->pos_x + (player->dir_x * cos(seta)
					- player->dir_y * sin(seta)) * 1.2));
	check_y = (int)((player->pos_y + (player->dir_x * sin(seta)
					+ player->dir_y * cos(seta)) * 1.2));
	if (map[check_y][check_x] == '1')
		return ;
	player->pos_x += (player->dir_x * cos(seta)
			- player->dir_y * sin(seta)) * 0.2;
	player->pos_y += (player->dir_x * sin(seta)
			+ player->dir_y * cos(seta)) * 0.2;
}

int	key_press(int key, t_window *window)
{
	if (key == 13)
		move_forward(window->player, window->map);
	if (key == 1)
		move_backward(window->player, window->map);
	if (key == 0)
		move_left(window->player, window->map);
	if (key == 2)
		move_right(window->player, window->map);
	if (key == 123)
		turn_left(window->player);
	if (key == 124)
		turn_right(window->player);
	if (key == 53)
		exit(0);
	return (0);
}
