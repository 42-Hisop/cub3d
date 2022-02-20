/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:15:40 by khee-seo          #+#    #+#             */
/*   Updated: 2022/02/20 12:22:37 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(cpy = (char *)malloc(sizeof(char) * (i + 1))))
		error("strdup malloc error");
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new = (char *)malloc(sizeof(char) * len)))
		error("strjoin malloc error");
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	unsigned int	i;

	if (dst == 0 || src == 0)
		return (0);
	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

int	ft_strstr(char const *s, char c)
{
	int	i;
	int	result;

	if (!s[0])
		return (0);
	i = 0;
	result = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			result++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		result++;
	return (result);
}
