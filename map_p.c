#include "includes/cub3d.h"
#include "includes/split.h"

int		check_map_w(char **line)
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

char	**map_parsing(char **line)
{
	//8부터 사용
	int		i;
	char 	**map;

	if (!(map = (char **)malloc(sizeof(char *) * (check_map_w(line) + 1))))
		return (error());
	i = 8;
	while (line[i])
	{

		i++;
	}
	map[j] = NULL;
	return (map);
}
