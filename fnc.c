
#include "includes/cub3d.h"
#include "includes/split.h"

void		fnc_allocate(char **f, char **c, t_window *window)
{
	int		num[6];
	int		i;
	int		j;

	i = 0;
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
}

t_window	*fnc_color(char **line, t_window *window)
{
	char	**f;
	char	**c;

	if (line_format(line[5], "F "))
		return (error());
	if (line_format(line[6], "C "))
		return (error());
	f = ft_split(ft_strdup(&line[5][2]), ',');
	c = ft_split(ft_strdup(&line[6][2]), ',');
	fnc_allocate(f, c, window);

	return (window);
}
