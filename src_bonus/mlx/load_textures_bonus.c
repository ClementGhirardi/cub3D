/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:58:24 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/16 13:26:37 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	load_texture(t_data *data, t_texture *texture)
{
	texture->img.img = mlx_xpm_file_to_image(
			data->mlx.mlx,
			texture->path,
			&texture->img.width,
			&texture->img.height);
	if (!texture->img.img)
		return (error_msg("Could not load texture"));
	texture->img.addr = mlx_get_data_addr(
			texture->img.img,
			&texture->img.bpp,
			&texture->img.line_len,
			&texture->img.endian);
	if (!texture->img.addr)
		return (error_msg("Could not get texture address"));
	return (0);
}

int	load_textures(t_data *data)
{
	if (load_texture(data, &data->config.north))
		return (1);
	if (load_texture(data, &data->config.south))
		return (1);
	if (load_texture(data, &data->config.west))
		return (1);
	if (load_texture(data, &data->config.east))
		return (1);
	if (load_texture(data, &data->config.door))
		return (1);
	return (0);
}
