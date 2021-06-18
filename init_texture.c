#include "includes/cub3d.h"

void	init_texture(t_window *window, t_texture *texture)
{
	int		i;

	 i = 0;
	 while (i < 4)
	 {
		texture[i].img = mlx_xpm_file_to_image(window->mlx, texture[i].adr, 
				texture[i].width, texture[i].height);
		texture[i].img_data = (unsigned int *)mlx_get_data_addr(
				texture[i].img, &texture[i].bpp, &texture[i].size_line, &texture[i].endian);
		i++;
	 }
}
