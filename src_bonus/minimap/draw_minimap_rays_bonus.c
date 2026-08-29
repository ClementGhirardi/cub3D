/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_rays_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:53:41 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/27 12:40:43 by clement-ghi      ###   ########.fr       */
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
		if (MINIMAP_X <= (int)x && (int)x < MINIMAP_X + minimap_size()
			&& MINIMAP_Y <= (int)y && (int)y < MINIMAP_Y + minimap_size())
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

	start.x = minimap_center_x();
	start.y = minimap_center_y();
	ray.camera_x = 2.0 * screen_x / WIN_WIDTH - 1.0;
	ray.dir_x = data->player.dir_x + data->player.plane_x * ray.camera_x;
	ray.dir_y = data->player.dir_y + data->player.plane_y * ray.camera_x;
	end = map_to_minimap(data,
			data->player.x + ray.dir_x * data->sprites.z_buffer[screen_x],
			data->player.y + ray.dir_y * data->sprites.z_buffer[screen_x]);
	draw_line(&data->mlx.frame, start, end, 0xFF0000);
}

void	draw_minimap_rays(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		draw_minimap_ray(data, x);
		x += 1;
	}
}
