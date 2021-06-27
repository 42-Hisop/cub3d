/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:39:33 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/27 21:47:41 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*error(void)
{
	write(1, "error", 5);
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
			error();
		num = num * 10 + (s[i] - '0');
		i++;
	}
	if (num < 0)
		error();
	if (num > 2147483647)
		error();
	return (num);
}

int		itorgb(int r, int g, int b)
{
	int		num;

	num = 0;
	if (256 <= r || 256 <= g || 256 <= b)
		error();
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
