/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move_to_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:15:20 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 01:56:55 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	is_floor(t_data *data, double x, double y)
{
	t_door	*door;
	int		map_x;
	int		map_y;
	int		len;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= data->map.height || map_x < 0)
		return (0);
	len = (int)ft_strlen(data->map.grid[map_y]);
	if (map_x >= len)
		return (0);
	if (data->map.grid[map_y][map_x] == '0')
		return (1);
	if (data->map.grid[map_y][map_x] != 'D')
		return (0);
	door = get_door_at(data, map_x, map_y);
	if (door && door->progress >= DOOR_WALKABLE)
		return (1);
	return (0);
}

int	can_move_to(t_data *data, double x, double y)
{
	double	r;

	r = COLLISION_RADIUS;
	if (!is_floor(data, x - r, y - r))
		return (0);
	if (!is_floor(data, x + r, y - r))
		return (0);
	if (!is_floor(data, x - r, y + r))
		return (0);
	if (!is_floor(data, x + r, y + r))
		return (0);
	return (1);
}
