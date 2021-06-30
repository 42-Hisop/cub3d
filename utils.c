/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:39:33 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/30 21:33:52 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*error(char *str)
{
	int		i;

	write(1, "error\n", 6);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	exit(1);
}

int		ft_atoi(char *s)
{
	unsigned long long		num;
	int						i;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (!('0' <= s[i] && s[i] <= '9'))
			error("atoi not number");
		num = num * 10 + (s[i] - '0');
		i++;
	}
	if (num < 0)
		error("atoi negative quantity");
	if (num > 2147483647)
		error("atoi out of range int");
	return (num);
}

int		itorgb(int r, int g, int b)
{
	int		num;

	num = 0;
	if (256 <= r || 256 <= g || 256 <= b)
		error("rgb out of range char");
	num = num + (r << 16);
	num = num + (g << 8);
	num = num + b;
	return (num);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i] || (s1[i] == '\0' && s2[i] == '\0'))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
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
