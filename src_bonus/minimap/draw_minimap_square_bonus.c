/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_square_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:11:56 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/27 12:45:20 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	draw_minimap_square(t_img *img, t_point *point, int size, int color)
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
