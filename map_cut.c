#include "includes/cub3d.h"
#include "includes/split.h"

int		check_map_h(char **line)
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

char	**cut_map(char **line)
{
	//8부터 사용
	int		i;
	int		j;
	char 	**map;

	if (!(map = (char **)malloc(sizeof(char *) * (check_map_h(line) + 1))))
		return (error());
	i = 8;
	j = 0;
	while (line[i])
	{
		map[j] = ft_strdup(line[i]);
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}
