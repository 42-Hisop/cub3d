/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:25:27 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/20 20:29:52 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "mlx/mlx.h"

int		main(int argc, char **argv)
{
	t_window window;
	t_player p;
	t_texture t[4];
	window.player = &p;
	window.texture = t;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, SCREEN_W,
			SCREEN_H, "cub3D");
	check_map(&window);
	mlx_hook(window.win, 2, 0, key_press, &window);
//	mlx_hook(window.win, 3, 0, key_press, &window);
	mlx_loop_hook(window.mlx, raycasting, &window);
	mlx_loop(window.mlx);
	return (0);
}
