/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:44:03 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/20 14:45:17 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	init_ray(t_data *data, t_ray *ray, int x)
{
	ray->camera_x = 2.0 * x / WIN_WIDTH - 1.0;
	ray->dir_x = data->player.dir_x + data->player.plane_x * ray->camera_x;
	ray->dir_y = data->player.dir_y + data->player.plane_y * ray->camera_x;
	ray->map_x = (int)data->player.x;
	ray->map_y = (int)data->player.y;
	ray->door_hit = 0;
}
