/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 00:17:57 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/26 16:56:47 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	count_sprites(t_data *data)
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
			if (data->map.grid[y][x] == '2')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static int	allocate_sprites(t_data *data)
{
	data->sprites.count = count_sprites(data);
	if (data->sprites.count == 0)
		return (0);
	data->sprites.list = malloc(sizeof(t_sprite)
			* data->sprites.count);
	if (!data->sprites.list)
		return (error_msg("Malloc failed"));
	return (0);
}

static void	fill_sprites(t_data *data)
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
			if (data->map.grid[y][x] == '2')
			{
				data->sprites.list[i].x = x + 0.5;
				data->sprites.list[i].y = y + 0.5;
				data->sprites.list[i].active = 1;
				data->map.grid[y][x] = '0';
				i++;
			}
			x++;
		}
		y++;
	}
}

int	extract_sprites(t_data *data)
{
	if (allocate_sprites(data))
		return (1);
	fill_sprites(data);
	return (0);
}
