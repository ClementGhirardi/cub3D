/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 22:25:55 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 14:08:00 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cast_ray(t_data *data, t_ray *ray, int x)
{
	init_ray(data, ray, x);
	init_delta(ray);
	init_step_side(data, ray);
	perform_dda(data, ray);
	if (ray->side == 0)
		ray->wall_dist = ray->side_x - ray->delta_x;
	else
		ray->wall_dist = ray->side_y - ray->delta_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}
