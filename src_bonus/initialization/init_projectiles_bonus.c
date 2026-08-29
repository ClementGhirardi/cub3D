/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_projectiles_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:31:47 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/21 16:10:49 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	init_projectiles(t_data *data)
{
	int	i;

	i = 0;
	while (i < MAX_PROJECTILES)
	{
		data->projectiles.list[i].x = 0.0;
		data->projectiles.list[i].y = 0.0;
		data->projectiles.list[i].dir_x = 0.0;
		data->projectiles.list[i].dir_y = 0.0;
		data->projectiles.list[i].active = 0;
		data->projectiles.list[i].state = PROJECTILE_FLYING;
		data->projectiles.list[i].explosion_frame = 0;
		data->projectiles.list[i].explosion_counter = 0;
		i++;
	}
}
