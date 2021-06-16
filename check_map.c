/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:20:51 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/16 20:38:02 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/split.h"

char	**cut_map(char **line);
void	map_valid(char **map);
t_window *fnc_color(char **line, t_window *window);

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

void	free_line(char **line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line[i]);
	free(line);
}

void	check_map(t_window *window)
{
	char	**line;
	int		map_fd;

	map_fd = open("maps/test2.cub", O_RDONLY);
	if (map_fd == -1)
		printf("open fail");
	line = split_line(map_fd);
	close(map_fd);
	tex_adr(line, window->texture);
	fnc_color(line, window);
	window->map = cut_map(line);
	map_valid(window->map);
	free_line(line);
	player_init(window->map, window->player);
}
