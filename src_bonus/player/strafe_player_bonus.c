/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strafe_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:15:20 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/15 17:12:12 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	strafe_player(t_data *data, double direction)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x
		- data->player.dir_y * MOVE_SPEED * direction;
	new_y = data->player.y
		+ data->player.dir_x * MOVE_SPEED * direction;
	if (can_move_to(data, new_x, data->player.y))
		data->player.x = new_x;
	if (can_move_to(data, data->player.x, new_y))
		data->player.y = new_y;
}
