/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:04:04 by khee-seo          #+#    #+#             */
/*   Updated: 2022/02/20 12:13:36 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_fnc_element(char **f, char **c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (f[i])
		i++;
	while (c[j])
		j++;
	if (i != 3 || j != 3)
		error("F,C element not 3");
}

int	map_is_last(char *str)
{
	if (str == NULL)
		return (1);
	if (str[0] == '0' || str[0] == '1' || str[0] == ' ')
		return (1);
	return (0);
}

void	fnc_allocate(char **f, char **c, t_window *window)
{
	int		num[6];
	int		i;
	int		j;

	i = 0;
	check_fnc_element(f, c);
	while (i < 3)
	{
		num[i] = ft_atoi(f[i]);
		i++;
	}
	j = 0;
	while (i < 6)
	{
		num[i] = ft_atoi(c[j]);
		i++;
		j++;
	}
	window->f_color = itorgb(num[0], num[1], num[2]);
	window->c_color = itorgb(num[3], num[4], num[5]);
	free_line(f);
	free_line(c);
}

int	fnc_color(char **line, t_window *window, char ***f, char ***c)
{
	if (line_format(line[window->line_n], "F "))
	{
		*f = ft_split(ft_strdup(&line[window->line_n][2]), ',');
	}
	if (line_format(line[window->line_n], "C "))
	{
		*c = ft_split(ft_strdup(&line[window->line_n][2]), ',');
	}
	if (*f && *c)
		fnc_allocate(*f, *c, window);
	return (0);
}
