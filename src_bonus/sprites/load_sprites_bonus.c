/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:34:20 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/26 16:49:48 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	load_sprite_frame(t_data *data, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(data->mlx.mlx,
			path, &img->width, &img->height);
	if (!img->img)
		return (error_msg("Could not load sprite"));
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_len, &img->endian);
	if (!img->addr)
		return (error_msg("Could not get sprite address"));
	return (0);
}

static void	calculate_hit_boxes(t_data *data)
{
	int	i;
	int	size;
	int	x;
	int	y;

	i = 0;
	while (i < SPRITE_FRAMES)
	{
		size = 0;
		y = data->sprites.frames[i].height / 2;
		x = 0;
		while (x < data->sprites.frames[i].width)
		{
			if ((get_pixel(&data->sprites.frames[i], x, y) & 0x00FFFFFF) != 0)
				size++;
			x++;
		}
		data->sprites.hit_box[i] = (double)size
			/ ((double) data->sprites.frames[i].width);
		i++;
	}
}

int	load_sprites(t_data *data)
{
	if (load_sprite_frame(data,
			&data->sprites.frames[0], "textures/torch_0.xpm"))
		return (1);
	if (load_sprite_frame(data,
			&data->sprites.frames[1], "textures/torch_1.xpm"))
		return (1);
	if (load_sprite_frame(data,
			&data->sprites.frames[2], "textures/torch_2.xpm"))
		return (1);
	if (load_sprite_frame(data,
			&data->sprites.frames[3], "textures/torch_3.xpm"))
		return (1);
	calculate_hit_boxes(data);
	return (0);
}
