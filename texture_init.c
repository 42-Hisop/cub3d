/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:37:17 by khee-seo          #+#    #+#             */
/*   Updated: 2021/06/27 21:38:01 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_init(t_window *window, t_texture *texture)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		texture[i].img = mlx_xpm_file_to_image(window->mlx, texture[i].adr,
				&texture[i].width, &texture[i].height);
		texture[i].img_data = (unsigned int *)mlx_get_data_addr(texture[i].img,
				&texture[i].bpp, &texture[i].size_line, &texture[i].endian);
		i++;
	}
}
