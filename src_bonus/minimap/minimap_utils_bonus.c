/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:11:56 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/15 19:36:58 by clement-ghi      ###   ########.fr       */
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
			if (MINIMAP_X <= point->x + x
				&& point->x + x < MINIMAP_X + minimap_size()
				&& MINIMAP_Y <= point->y + y
				&& point->y + y < MINIMAP_Y + minimap_size())
				put_pixel(img, point->x + x, point->y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_circle(t_img *img, t_point *center, int radius, int color)
{
	int	x;
	int	y;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				put_pixel(img, center->x + x, center->y + y, color);
			x++;
		}
		y++;
	}
}

int	minimap_size(void)
{
	return ((MINIMAP_RADIUS * 2 + 1) * MINIMAP_TILE);
}

int	minimap_center_x(void)
{
	return (MINIMAP_X
		+ (MINIMAP_RADIUS * 2 + 1) * MINIMAP_TILE / 2);
}

int	minimap_center_y(void)
{
	return (MINIMAP_Y
		+ (MINIMAP_RADIUS * 2 + 1) * MINIMAP_TILE / 2);
}
