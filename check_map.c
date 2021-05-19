/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:20:51 by khee-seo          #+#    #+#             */
/*   Updated: 2021/05/20 05:13:57 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	tex_file_adr();

void	check_map(t_player *player, t_texture *texture)
{
	int		map_fd;

	map_fd = open("maps/test.cub", O_RDONLY);
	if (map_fd == -1)
		printf("open fail");

	printf("map fd = %d\n", map_fd);

	// 맵 파싱 및 플레이어위치 지정해주기
	player_init(player);
}
