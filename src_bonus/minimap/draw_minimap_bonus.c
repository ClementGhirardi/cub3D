/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:33:10 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/27 13:47:46 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	draw_minimap_background(t_data *data)
{
	t_point	point;

	point.x = MINIMAP_X;
	point.y = MINIMAP_Y;
	draw_minimap_square(&data->mlx.frame, &point, minimap_size(), 0x202020);
}

static void draw_minimap_sprites(t_data *data)
{
	int		end_x;
	int		end_y;
	int		start_x;
	int		start_y;
	t_point	center;
	int		i;

	start_x = (int)data->player.x - MINIMAP_RADIUS - 1;
	start_y = (int)data->player.y - MINIMAP_RADIUS - 1;
	end_y = (int)data->player.y + MINIMAP_RADIUS + 1;
	end_x = (int)data->player.x + MINIMAP_RADIUS + 1;
	i = 0;
	while (i < data->sprites.count)
	{
		if (start_x < (int) data->sprites.list[i].x
			&& (int) data->sprites.list[i].x < end_x
			&& start_y < (int) data->sprites.list[i].y
			&& (int) data->sprites.list[i].y < end_y
			&& data->sprites.list[i].active)
		{
			center = map_to_minimap(data, data->sprites.list[i].x,
				data->sprites.list[i].y);
			draw_minimap_circle(&data->mlx.frame, &center, 4, 0x0000FF);
		}
		i++;
	}
}

static void	draw_minimap_player(t_data *data)
{
	t_point	center;

	center.x = minimap_center_x();
	center.y = minimap_center_y();
	draw_minimap_circle(&data->mlx.frame, &center, 4, 0xFF0000);
}

static void	draw_minimap_border(t_data *data)
{
	int	x;
	int	y;

	x = MINIMAP_X;
	while (x < MINIMAP_X + minimap_size())
	{
		put_pixel(&data->mlx.frame, x, MINIMAP_Y, 0xFFFFFF);
		put_pixel(&data->mlx.frame, x,
			MINIMAP_Y + minimap_size() - 1, 0xFFFFFF);
		x++;
	}
	y = MINIMAP_Y;
	while (y < MINIMAP_Y + minimap_size())
	{
		put_pixel(&data->mlx.frame, MINIMAP_X, y, 0xFFFFFF);
		put_pixel(&data->mlx.frame,
			MINIMAP_X + minimap_size() - 1, y, 0xFFFFFF);
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	draw_minimap_background(data);
	draw_minimap_tiles(data);
	draw_minimap_rays(data);
	draw_minimap_sprites(data);
	draw_minimap_player(data);
	draw_minimap_border(data);
}
