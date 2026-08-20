/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:30:11 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 13:05:50 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	destroy_texture(t_data *data, t_texture *texture)
{
	if (texture->img.img)
	{
		mlx_destroy_image(data->mlx.mlx, texture->img.img);
		texture->img.img = NULL;
		texture->img.addr = NULL;
	}
}

void	destroy_mlx(t_data *data)
{
	if (!data->mlx.mlx)
		return ;
	destroy_texture(data, &data->config.north);
	destroy_texture(data, &data->config.south);
	destroy_texture(data, &data->config.west);
	destroy_texture(data, &data->config.east);
	if (data->mlx.frame.img)
	{
		mlx_destroy_image(data->mlx.mlx, data->mlx.frame.img);
		data->mlx.frame.img = NULL;
		data->mlx.frame.addr = NULL;
	}
	if (data->mlx.win)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		data->mlx.win = NULL;
	}
	mlx_destroy_display(data->mlx.mlx);
	free(data->mlx.mlx);
	data->mlx.mlx = NULL;
}
