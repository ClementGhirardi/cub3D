/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:31:47 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 01:58:12 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	init_sprites(t_data *data)
{
	int	i;

	data->sprites.list = NULL;
	data->sprites.count = 0;
	data->sprites.current_frame = 0;
	data->sprites.anim_counter = 0;
	i = 0;
	while (i < SPRITE_FRAMES)
	{
		init_img(&data->sprites.frames[i]);
		i++;
	}
}
