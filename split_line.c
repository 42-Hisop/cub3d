/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:14:58 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/30 19:20:05 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*check_m(char *rd, int rd_i, char *backup, char c)
{
	int		count;

	count = 1;
	while (rd[rd_i] && rd[rd_i] != c)
	{
		rd_i++;
		count++;
	}
	if (!(backup = (char *)malloc(sizeof(char) * count + 1)))
		error("split malloc error");
	return (backup);
}

char		**ft_split(char *rd, char c, int i, int rd_i)
{
	int		j;
	char	**backup;

	if (!(backup = (char **)malloc(sizeof(char *) * (ft_strstr(rd, c) + 1))))
		return (0);
	while (i < ft_strstr(rd, c))
	{
		j = 0;
		backup[i] = check_m(rd, rd_i, backup[i], c);
		while (rd[rd_i] && rd[rd_i] != c)
		{
			backup[i][j] = rd[rd_i];
			j++;
			rd_i++;
		}
		backup[i][j] = '\0';
		if (rd[rd_i] == c)
			rd_i++;
		i++;
	}
	backup[i] = NULL;
	free(rd);
	return (backup);
}

char		*save(char *rd, char *buf)
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

char		**split_line(int fd)
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
	backup = ft_split(rd, '\n', 0, 0);
	return (backup);
}
