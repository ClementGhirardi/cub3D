/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_rays_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:53:41 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/20 13:26:36 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	draw_line(t_img *img, t_point start, t_point end, int color)
{
	double	x;
	double	y;
	int		steps;
	int		i;

	steps = abs(end.x - start.x);
	if (abs(end.y - start.y) > steps)
		steps = abs(end.y - start.y);
	if (steps == 0)
		return ;
	x = start.x;
	y = start.y;
	i = 0;
	while (i <= steps)
	{
		put_pixel(img, (int)x, (int)y, color);
		x += (double)(end.x - start.x) / steps;
		y += (double)(end.y - start.y) / steps;
		i++;
	}
}

static void	draw_minimap_ray(t_data *data, int screen_x)
{
	t_ray	ray;
	t_point	start;
	t_point	end;

	cast_ray(data, &ray, screen_x);
	start.x = (int)(data->player.x * MINIMAP_TILE);
	start.y = (int)(data->player.y * MINIMAP_TILE);
	end.x = (int)((data->player.x
				+ ray.dir_x * ray.wall_dist) * MINIMAP_TILE);
	end.y = (int)((data->player.y
				+ ray.dir_y * ray.wall_dist) * MINIMAP_TILE);
	draw_line(&data->mlx.frame, start, end, 0xFF0000);
}

void	draw_minimap_rays(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		draw_minimap_ray(data, x);
		x += 60;
	}
}
