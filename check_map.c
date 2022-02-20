/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:20:51 by khee-seo          #+#    #+#             */
/*   Updated: 2022/02/19 14:01:28 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			line_format(char *line, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (line[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

int			tex_adr_allocate(char **line, t_texture *tex,
		t_window *window, int i)
{
	tex[i].adr = ft_strdup(&line[window->line_n][3]);
	return (0);
}

t_texture	*tex_adr(char **line, t_texture *tex, t_window *window)
{
	int		flag[4];

	while (flag[0] || flag[1] || flag[2] || flag[3])
	{
		if (map_is_last(line[window->line_n]))
			error("map data is written first");
		if (line_format(line[window->line_n], "NO "))
			flag[0] = tex_adr_allocate(line, tex, window, 0);
		if (line_format(line[window->line_n], "SO "))
			flag[1] = tex_adr_allocate(line, tex, window, 1);
		if (line_format(line[window->line_n], "WE "))
			flag[2] = tex_adr_allocate(line, tex, window, 2);
		if (line_format(line[window->line_n], "EA "))
			flag[3] = tex_adr_allocate(line, tex, window, 3);
		if (line_format(line[window->line_n], "F ") ||
				line_format(line[window->line_n], "C "))
			error("wall texture adr error");
		window->line_n++;
	}
	return (tex);
}

void		check_map(t_window *window, char *map_name)
{
	char	**line;
	int		map_fd;

	window->line_n = 0;
	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
		error("file open error");
	line = split_line(map_fd);
	close(map_fd);
	tex_adr(line, window->texture, window);
	fnc_color(line, window);
	window->map = map_cut(line, window);
	map_valid(window->map);
	free_line(line);
	player_init(window->map, window->player, 0);
	texture_init(window, window->texture);
}
