/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:38:43 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 00:42:07 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	draw_sprite_stripe(t_data *data,
		t_sprite_render *render, int stripe)
{
	t_img	*img;
	int		tex_x;
	int		tex_y;
	int		y;
	int		color;

	img = &data->sprites.frames[data->sprites.current_frame];
	tex_x = (int)(256 * (stripe
				- (-render->width / 2 + render->screen_x))
			* img->width / render->width) / 256;
	y = render->start_y;
	while (y < render->end_y)
	{
		tex_y = (((y * 256 - WIN_HEIGHT * 128 + render->height * 128)
					* img->height) / render->height) / 256;
		color = get_pixel(img, tex_x, tex_y);
		if ((color & 0x00FFFFFF) != 0)
			put_pixel(&data->mlx.frame, stripe, y, color);
		y++;
	}
}

void	draw_sprite(t_data *data, t_sprite_render *render)
{
	int	stripe;

	stripe = render->start_x;
	while (stripe < render->end_x)
	{
		if (stripe >= 0
			&& stripe < WIN_WIDTH
			&& render->transform_y > 0
			&& render->transform_y < data->sprites.z_buffer[stripe])
		{
			draw_sprite_stripe(data, render, stripe);
		}
		stripe++;
	}
}
