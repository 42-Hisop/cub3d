/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:14:23 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/16 18:48:40 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		validinwall(char c)
{
	if (c == '0' || c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return (1);
	return (0);
}

int		wallcheck_w(char **map)
{
	int		i;
	int		j;
	int		flag;

	i = 0;	
	while (map[i])
	{
		flag = 0;
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' && flag == 0)
				flag = 1;
			if (validinwall(map[i][j]) && flag == 0)
				return (1);
			if (validinwall(map[i][j]) && (map[i][j - 1] == ' ' || map[i][j + 1] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		wallcheck_h(char **map)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	while (map[j][i])
	{
		while (map[j])
		{
			if (map[j][i] == '1' && flag == 0)
				flag = 1;
			if (validinwall(map[j][i]) && flag == 0)
				return (1);
			if (validinwall(map[j][i]) && (map[j][i - 1] == ' ' || map[j][i + 1] == ' '))
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int		validcheck(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'E'
				|| map[i][j] == 'W' || map[i][j] == 'S' || map[i][j] == 'N'
				|| map[i][j] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	map_valid(char **map)
{
	if (validcheck(map))
		error();
	if (wallcheck_w(map))
		error();
	if (wallcheck_h(map))
		error();
	return ;
}
