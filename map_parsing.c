/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:14:23 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/09 21:55:25 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		validcheck(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'E'
				|| map[i][j] == 'W' || map[i][j] == 'S' || map[i][j] == 'N'))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	parsing(void);
{
	if (validcheck(map))
		return (error);

	return ;
}
