#include "includes/cub3d.h"
#include "includes/split.h"

char 	*check_m(char *rd, int rd_i, char *backup, char c)
{
	int count;

	count = 1;
	while (rd[rd_i] && rd[rd_i] != c)
	{
		rd_i++;
		count++;
	}
	if (!(backup = (char *)malloc(sizeof(char) * count + 1)))
		return (0);
	return (backup);
}

char	**ft_split(char *rd, char c)
{
	int 	i;
	int		j;
	int		rd_i;
	char	**backup;

	if(!(backup = (char **)malloc(sizeof(char *) * (ft_strstr(rd, c) + 1))))
		return (0);
	i = 0;
	rd_i = 0;
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

char 	**split_line(int fd)
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
