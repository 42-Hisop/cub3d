/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:20:51 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/08 16:02:46 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/split.h"

int		line_format(char *line, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (line[i] != str[i])
			return (1);
		i++;
	}
	return (0);
}

t_texture	*tex_adr(char **line, t_texture *tex)
{
	int		i;

	if (line_format(line[0], "NO "))
		return (error());
	if (line_format(line[1], "SO "))
		return (error());
	if (line_format(line[2], "WE "))
		return (error());
	if (line_format(line[3], "EA "))
		return (error());
	i = 0;
	while (i < 4)
	{
		tex[i].adr = ft_strdup(&line[i][3]);
		i++;
	}
	return (tex);
}

void	check_map(t_window *window)
{
	char	**line;
	int		map_fd;

	map_fd = open("maps/test.cub", O_RDONLY);
	if (map_fd == -1)
		printf("open fail");
	line = split_line(map_fd);
	close(map_fd);
	window->texture = tex_adr(line, window->texture);
//	fnc_color(line);
	// 맵 파싱 및 플레이어위치 지정해주기
//	player_init(player);
}
