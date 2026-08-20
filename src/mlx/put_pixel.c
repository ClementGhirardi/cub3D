/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:14:58 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/14 13:15:04 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
