/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:54:48 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/31 16:36:52 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	update_anim(t_data *data)
{
	data->sprites.anim_counter++;
	if (data->sprites.anim_counter >= SPRITE_ANIM_SPEED)
	{
		data->sprites.anim_counter = 0;
		data->sprites.current_frame++;
		if (data->sprites.current_frame >= SPRITE_FRAMES)
			data->sprites.current_frame = 0;
	}
}

void	update_sprites(t_data *data)
{
	sort_sprites(data);
	update_anim(data);
	move_sprites(data);
}
