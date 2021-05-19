/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:25:27 by khee-seo          #+#    #+#             */
/*   Updated: 2021/05/20 03:16:05 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		main(int argc, char **argv)
{
	t_window window;
	t_player p;
	t_texture t;
	window.player = &p;
	window.texture = &t;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, SCREEN_W,
			SCREEN_H, "main_window");
	check_map(window.player, window.texture);
//	mlx_hook(window.win, 2, 0, key_press, &window);
//	mlx_hook(window.win, 3, 0, key_press, &window);
	mlx_loop_hook(window.mlx, raycasting, &window);
	mlx_loop(window.mlx);
	return (0);
}
