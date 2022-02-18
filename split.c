#include "cub3d.h"

static	char	**ft_free_all(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static	size_t	ft_num_strs(char const *s, char c)
{
	size_t	i;
	size_t	result;

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

static	void	ft_num_str(char **str, int *str_len, char c)
{
	size_t	i;

	*str += *str_len;
	*str_len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}

static void	ft_spinit(int *i, int *temp_len)
{
	*i = 0;
	*temp_len = 0;
	return ;
}

char	**ft_split(char *s, char c)
{
	char	**result;
	char	*temp_str;
	int	temp_len;
	int	num_strs;
	int	i;

	ft_spinit(&i, &temp_len);
	num_strs = ft_num_strs(s, c);
	temp_str = (char *)s;
	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (num_strs + 1));
	if (!result)
		return (NULL);
	while (i < num_strs)
	{
		ft_num_str(&temp_str, &temp_len, c);
		result[i] = malloc(sizeof(char) * (temp_len + 1));
		if (!result[i])
			return (ft_free_all(result));
		ft_strlcpy(result[i], temp_str, temp_len + 1);
		i++;
	}
	result[i] = NULL;
	return (result);
}
