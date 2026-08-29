/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:11:56 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/27 12:46:10 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

t_point	map_to_minimap(t_data *data, double x, double y)
{
	t_point	point;
	int		center_x;
	int		center_y;

	center_x = minimap_center_x();
	center_y = minimap_center_y();
	point.x = center_x
		+ (int)((x - data->player.x) * MINIMAP_TILE);
	point.y = center_y
		+ (int)((y - data->player.y) * MINIMAP_TILE);
	return (point);
}

int	minimap_size(void)
{
	return ((MINIMAP_RADIUS * 2 + 1) * MINIMAP_TILE);
}

int	minimap_center_x(void)
{
	return (MINIMAP_X
		+ (MINIMAP_RADIUS * 2 + 1) * MINIMAP_TILE / 2);
}

int	minimap_center_y(void)
{
	return (MINIMAP_Y
		+ (MINIMAP_RADIUS * 2 + 1) * MINIMAP_TILE / 2);
}
