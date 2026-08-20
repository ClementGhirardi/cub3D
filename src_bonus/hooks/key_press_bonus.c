/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 12:46:06 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 01:58:59 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	if (keycode == KEY_W || keycode == KEY_Z)
		data->keys.up = 1;
	else if (keycode == KEY_S)
		data->keys.down = 1;
	else if (keycode == KEY_A || keycode == KEY_Q)
		data->keys.left = 1;
	else if (keycode == KEY_D)
		data->keys.right = 1;
	else if (keycode == KEY_LEFT)
		data->keys.rot_left = 1;
	else if (keycode == KEY_RIGHT)
		data->keys.rot_right = 1;
	else if (keycode == KEY_E)
		open_door(data);
	return (0);
}
