/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_closed_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 19:43:21 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/15 17:12:13 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	is_open_cell(t_map *map, int x, int y)
{
	int	current_len;
	int	up_len;
	int	down_len;

	current_len = (int)ft_strlen(map->grid[y]);
	if (y == 0 || y == map->height - 1)
		return (1);
	if (x == 0 || x >= current_len - 1)
		return (1);
	up_len = (int)ft_strlen(map->grid[y - 1]);
	down_len = (int)ft_strlen(map->grid[y + 1]);
	if (x >= up_len || x >= down_len)
		return (1);
	if (map->grid[y][x - 1] == ' '
		|| map->grid[y][x + 1] == ' '
		|| map->grid[y - 1][x] == ' '
		|| map->grid[y + 1][x] == ' ')
		return (1);
	return (0);
}

int	validate_map_closed(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			if (is_player_char(data->map.grid[y][x])
				|| data->map.grid[y][x] == '0')
			{
				if (is_open_cell(&data->map, x, y))
					return (error_msg("Map is not closed"));
			}
			x++;
		}
		y++;
	}
	return (0);
}
