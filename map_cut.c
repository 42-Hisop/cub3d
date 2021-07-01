/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:30:04 by khee-seo          #+#    #+#             */
/*   Updated: 2021/07/01 14:53:08 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_map_w(char **line, t_window *window)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = window->line_n;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (count <= j)
				count = j;
			j++;
		}
		i++;
	}
	return (count);
}

int			check_map_h(char **line, t_window *window)
{
	int		i;
	int		count;

	i = window->line_n;
	count = 0;
	while (line[i])
	{
		i++;
		count++;
	}
	return (count);
}

char		*dup_map(char *map, char *line, int map_w)
{
	int		i;

	i = 0;
	while (line[i])
	{
		map[i] = line[i];
		i++;
	}
	while (i <= map_w)
	{
		map[i] = ' ';
		i++;
	}
	map[i] = '\0';
	return (map);
}

char		*make_empty_line(char *map, int map_w)
{
	int		i;

	if (!(map = (char *)malloc(sizeof(char) * (map_w + 1))))
		error("map malloc error");
	i = 0;
	while (i < map_w)
	{
		map[i] = '\0';
		i++;
	}
	map[i] = '\0';
	return (map);
}

char		**cut_map(char **line, t_window *window)
{
	int		map_w;
	int		map_h;
	int		i;
	char	**map;

	map_w = check_map_w(line, window);
	map_h = check_map_h(line, window);
	if (!(map = (char **)malloc(sizeof(char *) * (map_h + 2))))
		error("map malloc error");
	i = 0;
	while (i < map_h)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (map_w + 1))))
			error("map malloc error");
		map[i] = dup_map(map[i], line[window->line_n], map_w);
		i++;
		window->line_n++;
	}
	map[i] = make_empty_line(map[i], map_w);
	map[i + 1] = NULL;
	return (map);
}
