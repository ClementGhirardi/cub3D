/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_door_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:10:58 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 10:12:00 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	hit_vertical_door(t_data *data,
		t_ray *ray, t_door *door)
{
	double	dist;
	double	pos;

	if (ray->dir_x == 0.0)
		return (0);
	dist = (door->x + 0.5 - data->player.x) / ray->dir_x;
	pos = data->player.y + dist * ray->dir_y - door->y;
	if (pos < 0.0 || pos >= 1.0)
		return (0);
	if (pos < door->progress)
		return (0);
	ray->wall_dist = dist;
	ray->side = 0;
	return (1);
}

static int	hit_horizontal_door(t_data *data,
		t_ray *ray, t_door *door)
{
	double	dist;
	double	pos;

	if (ray->dir_y == 0.0)
		return (0);
	dist = (door->y + 0.5 - data->player.y) / ray->dir_y;
	pos = data->player.x + dist * ray->dir_x - door->x;
	if (pos < 0.0 || pos >= 1.0)
		return (0);
	if (pos < door->progress)
		return (0);
	ray->wall_dist = dist;
	ray->side = 1;
	return (1);
}

int	ray_hit_door(t_data *data, t_ray *ray)
{
	t_door	*door;

	door = get_door_at(data, ray->map_x, ray->map_y);
	if (!door)
		return (0);
	if (door->vertical)
		return (hit_vertical_door(data, ray, door));
	return (hit_horizontal_door(data, ray, door));
}
