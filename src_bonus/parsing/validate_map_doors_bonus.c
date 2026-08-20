/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_doors_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 12:43:05 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 16:36:57 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static char	get_map_cell(t_map *map, int x, int y)
{
	if (y < 0 || y >= map->height)
		return (' ');
	if (x < 0)
		return (' ');
	if (x >= (int)ft_strlen(map->grid[y]))
		return (' ');
	return (map->grid[y][x]);
}

static int	is_door_floor(char c)
{
	return (c == '0' || is_player_char(c));
}

static int	is_valid_door(t_map *map, int x, int y)
{
	char	left;
	char	right;
	char	up;
	char	down;

	left = get_map_cell(map, x - 1, y);
	right = get_map_cell(map, x + 1, y);
	up = get_map_cell(map, x, y - 1);
	down = get_map_cell(map, x, y + 1);
	if (up == '1' && down == '1'
		&& is_door_floor(left) && is_door_floor(right))
		return (1);
	if (left == '1' && right == '1'
		&& is_door_floor(up) && is_door_floor(down))
		return (1);
	return (0);
}

int	validate_map_doors(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			if (data->map.grid[y][x] == 'D'
				&& !is_valid_door(&data->map, x, y))
				return (error_msg("Invalid door placement"));
			x++;
		}
		y++;
	}
	return (0);
}
