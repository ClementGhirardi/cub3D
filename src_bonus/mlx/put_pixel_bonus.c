/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:14:58 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/15 17:12:13 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= img->width
		|| y < 0 || y >= img->height)
		return ;
	pixel = img->addr
		+ (y * img->line_len
			+ x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}
