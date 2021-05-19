/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:25:27 by khee-seo          #+#    #+#             */
/*   Updated: 2021/05/19 02:13:46 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		main(int argc, char **argv)
{
	t_window window;
	t_player player;
	t_texture texture;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, screenWidth,
			screenHeight, "main_window");
	check_map(player, texture);
	mlx_hook(window.win, 2, 0, key_press, &window);
	mlx_hook(window.win, 3, 0, key_press, &window);
	mlx_loop_hook(window.mlx, raycast, &window);
	mlx_loop(window.mlx);
	return (0);
}
