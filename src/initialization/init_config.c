/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:30:11 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 13:05:11 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	data->config.floor_color = -1;
	data->config.ceiling_color = -1;
}
