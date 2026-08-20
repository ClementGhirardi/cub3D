/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:33:10 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/15 19:14:11 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	draw_square(t_img *img, t_point *point, int size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			put_pixel(img, point->x + x, point->y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_minimap_tiles(t_data *data)
{
	int		x;
	int		y;
	t_point	point;

	y = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			point.x = x * MINIMAP_TILE;
			point.y = y * MINIMAP_TILE;
			if (data->map.grid[y][x] == '1')
				draw_square(&data->mlx.frame,
					&point, MINIMAP_TILE, data->config.ceiling_color);
			else if (data->map.grid[y][x] == '0')
				draw_square(&data->mlx.frame,
					&point, MINIMAP_TILE, data->config.floor_color);
			x++;
		}
		y++;
	}
}

void	draw_minimap_player(t_data *data)
{
	int		x;
	int		y;
	t_point	point;

	x = (int)(data->player.x * MINIMAP_TILE);
	y = (int)(data->player.y * MINIMAP_TILE);
	point.x = x - 2;
	point.y = y - 2;
	draw_square(&data->mlx.frame, &point, 5, 0xFF0000);
}

void	draw_minimap(t_data *data)
{
	draw_minimap_tiles(data);
	draw_minimap_rays(data);
	draw_minimap_player(data);
}
