/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:30:11 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 11:44:21 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	init_config(t_data *data)
{
	data->config.north.path = NULL;
	init_img(&data->config.north.img);
	data->config.south.path = NULL;
	init_img(&data->config.south.img);
	data->config.west.path = NULL;
	init_img(&data->config.west.img);
	data->config.east.path = NULL;
	init_img(&data->config.east.img);
	data->config.door.path = NULL;
	init_img(&data->config.door.img);
	data->config.floor_color = -1;
	data->config.ceiling_color = -1;
}
