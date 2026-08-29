/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_projectile_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 14:45:04 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/21 16:11:47 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	shoot_projectile(t_data *data)
{
	int				i;
	t_projectile	*p;

	i = 0;
	while (i < MAX_PROJECTILES)
	{
		if (!data->projectiles.list[i].active)
		{
			p = &data->projectiles.list[i];
			p->x = data->player.x;
			p->y = data->player.y;
			p->dir_x = data->player.dir_x;
			p->dir_y = data->player.dir_y;
			p->active = 1;
			p->state = PROJECTILE_FLYING;
			p->explosion_frame = 0;
			p->explosion_counter = 0;
			return ;
		}
		i++;
	}
}
