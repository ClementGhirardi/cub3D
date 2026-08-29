/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_sprite_z_buffer_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 16:20:55 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/21 16:21:07 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	reset_sprite_z_buffer(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		data->sprites.sprite_z_buffer[x] = 1e30;
		x++;
	}
}
