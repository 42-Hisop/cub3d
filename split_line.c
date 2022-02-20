/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:14:58 by khee-seo          #+#    #+#             */
/*   Updated: 2022/02/20 12:12:48 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*save(char *rd, char *buf)
{
	char	*temp;

	if (rd == NULL)
		rd = ft_strdup(buf);
	else
	{
		temp = ft_strjoin(rd, buf);
		free(rd);
		rd = temp;
	}
	return (rd);
}

char	**split_line(int fd)
{
	char	buf[2];
	char	*rd;
	char	**backup;
	int		index;

	rd = NULL;
	while (1)
	{
		if (0 == read(fd, buf, 1))
			break ;
		buf[1] = '\0';
		rd = save(rd, buf);
	}
	backup = ft_split(rd, '\n');
	return (backup);
}
