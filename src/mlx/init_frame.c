/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:12:37 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/14 13:15:10 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_frame(t_data *data)
{
	t_img	*frame;

	frame = &data->mlx.frame;
	frame->width = WIN_WIDTH;
	frame->height = WIN_HEIGHT;
	frame->img = mlx_new_image(data->mlx.mlx,
			frame->width, frame->height);
	if (!frame->img)
		return (error_msg("Frame creation failed"));
	frame->addr = mlx_get_data_addr(frame->img,
			&frame->bpp,
			&frame->line_len,
			&frame->endian);
	if (!frame->addr)
		return (error_msg("Frame address failed"));
	return (0);
}
