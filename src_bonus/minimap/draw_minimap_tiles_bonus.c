/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_tiles_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 19:10:36 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/27 12:46:04 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	draw_minimap_tile(t_data *data, int map_x, int map_y)
{
	t_point	point;
	char	cell;

	if (map_y < 0 || map_y >= data->map.height)
		return ;
	if (map_x < 0 || map_x >= (int)ft_strlen(data->map.grid[map_y]))
		return ;
	cell = data->map.grid[map_y][map_x];
	point = map_to_minimap(data, map_x, map_y);
	if (cell == '1')
		draw_minimap_square(&data->mlx.frame, &point,
			MINIMAP_TILE, data->config.ceiling_color);
	else if (cell == '0')
		draw_minimap_square(&data->mlx.frame, &point,
			MINIMAP_TILE, data->config.floor_color);
	else if (cell == 'D')
		draw_minimap_square(&data->mlx.frame, &point,
			MINIMAP_TILE, 0x8B4513);
}

void	draw_minimap_tiles(t_data *data)
{
	int		map_x;
	int		map_y;
	int		start_x;
	int		start_y;

	start_x = (int)data->player.x - MINIMAP_RADIUS - 1;
	start_y = (int)data->player.y - MINIMAP_RADIUS - 1;
	map_y = start_y;
	while (map_y <= (int)data->player.y + MINIMAP_RADIUS + 1)
	{
		map_x = start_x;
		while (map_x <= (int)data->player.x + MINIMAP_RADIUS + 1)
		{
			draw_minimap_tile(data, map_x, map_y);
			map_x++;
		}
		map_y++;
	}
}
