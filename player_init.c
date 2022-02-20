/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:53:21 by khee-seo          #+#    #+#             */
/*   Updated: 2022/02/20 12:10:56 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vector_init2(char c, t_player *player)
{
	if (c == 'S' || c == 'N')
	{
		if (c == 'S')
		{
			player->dir_x = 0;
			player->dir_y = 1;
			player->plane_x = -0.66;
		}
		if (c == 'N')
		{
			player->dir_x = 0;
			player->dir_y = -1;
			player->plane_x = 0.66;
		}
		player->plane_y = 0;
	}
}

void	vector_init(char c, t_player *player)
{
	if (c == 'E' || c == 'W')
	{
		if (c == 'E')
		{
			player->dir_x = 1;
			player->dir_y = 0;
			player->plane_y = 0.66;
		}
		if (c == 'W')
		{
			player->dir_x = -1;
			player->dir_y = 0;
			player->plane_y = -0.66;
		}
		player->plane_x = 0;
	}
	else
		vector_init2(c, player);
}

void	player_init(char **map, t_player *player, int count)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'W' ||
					map[i][j] == 'S' || map[i][j] == 'N')
			{
				player->pos_x = j;
				player->pos_y = i;
				vector_init(map[i][j], player);
				count++;
			}
			j++;
		}
		i++;
	}
	if (2 <= count)
		error("multiple player locations");
	if (count == 0)
		error("player location not found");
}
