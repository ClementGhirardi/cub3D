/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_projectiles_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 14:45:04 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/31 16:19:01 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	hit_sprite(t_data *data, double x, double y)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->sprites.count)
	{
		if (fabs(data->sprites.list[i].x - x)
			< data->sprites.hit_box[data->sprites.current_frame] / 2
			&& fabs(data->sprites.list[i].y - y)
			< data->sprites.hit_box[data->sprites.current_frame] / 2)
		{
			j = 0;
			while (j < data->sprites.count)
			{
				if ((int)data->sprites.list[j].x == (int)x
					&& (int)data->sprites.list[j].y == (int)y)
					return (data->sprites.list[j].active = 0, 1);
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

static int	hit_player(t_data *data, double x, double y)
{
	double	dist;

	dist = sqrt(pow(x - data->player.x, 2) + pow(y - data->player.y, 2));
	if (dist < HIT_BOX)
		return (1);
	return (0);
}

int	hit_obstacle(t_data *data, double x, double y, int type)
{
	int		map_x;
	int		map_y;
	t_door	*door;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0
		|| map_x >= data->map.width
		|| map_y >= data->map.height)
		return (1);
	if (data->map.grid[map_y][map_x] == '1')
		return (1);
	if (type == 1)
	{
		if (hit_sprite(data, x, y))
			return (1);
	}
	door = get_door_at(data, map_x, map_y);
	if (door && door->progress < DOOR_WALKABLE)
		return (1);
	if (hit_player(data, x, y))
		close_game(data);
	return (0);
}
