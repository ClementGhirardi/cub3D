/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_doors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 09:56:43 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 09:58:21 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	count_doors(t_data *data)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			if (data->map.grid[y][x] == 'D')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static int	is_vertical_door(t_data *data, int x, int y)
{
	if (data->map.grid[y - 1][x] == '1'
		&& data->map.grid[y + 1][x] == '1')
		return (1);
	return (0);
}

static void	fill_doors(t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			if (data->map.grid[y][x] == 'D')
			{
				data->doors.list[i].x = x;
				data->doors.list[i].y = y;
				data->doors.list[i].progress = 0.0;
				data->doors.list[i].state = DOOR_CLOSED;
				data->doors.list[i].vertical = is_vertical_door(data, x, y);
				i++;
			}
			x++;
		}
		y++;
	}
}

int	extract_doors(t_data *data)
{
	data->doors.count = count_doors(data);
	if (data->doors.count == 0)
		return (0);
	data->doors.list = malloc(sizeof(t_door) * data->doors.count);
	if (!data->doors.list)
		return (error_msg("Malloc failed"));
	fill_doors(data);
	return (0);
}
