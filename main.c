/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:25:27 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/27 17:57:30 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "mlx/mlx.h"

char	*param_main(int argc, char **argv)
{
	int		i;
	char	*new;

	if (argc != 2)
		error();
	new = ft_strdup(argv[1]);
	while (new[i])
		i++;
	if (ft_strcmp(&new[i - 4], ".cub") != 0)
		error();
	return (new);	
}

int		main(int argc, char **argv)
{
	t_window window;
	t_player p;
	t_texture t[4];
	char	*map_name;

	window.player = &p;
	window.texture = t;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, SCREEN_W,
			SCREEN_H, "cub3D");
	map_name = param_main(argc, argv);
	check_map(&window, map_name);
	free(map_name);
	mlx_hook(window.win, 2, 0, key_press, &window);
//	mlx_hook(window.win, 3, 0, key_press, &window);
	mlx_loop_hook(window.mlx, raycasting, &window);
	mlx_loop(window.mlx);
	return (0);
}
