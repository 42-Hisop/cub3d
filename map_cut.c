/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:30:04 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/27 20:32:59 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_map_w(char **line)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
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

int			check_map_h(char **line)
{
	int		i;
	int		count;

	i = 8;
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

char		**cut_map(char **line)
{
	int		map_w;
	int		map_h;
	int		i;
	int		j;
	char	**map;

	map_w = check_map_w(line);
	map_h = check_map_h(line);
	if (!(map = (char **)malloc(sizeof(char *) * (map_h + 1))))
		return (error());
	i = 0;
	j = 8;
	while (i < map_h)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (map_w + 1))))
			return (error());
		map[i] = dup_map(map[i], line[j], map_w);
		i++;
		j++;
	}
	map[i] = NULL;
	return (map);
}
