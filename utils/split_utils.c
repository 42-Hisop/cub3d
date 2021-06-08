#include "../includes/cub3d.h"

int		ft_strlen(char const *s)
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
		return (0);
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
		return (0);
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

int		ft_strstr(char *rd, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (rd[i])
	{
		if (rd[i] == c)
			count++;
		i++;
	}
	if (count != 0)
		count++;
	return (count);
}
