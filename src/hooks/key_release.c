/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 12:46:06 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 16:47:24 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_Z)
		data->keys.up = 0;
	else if (keycode == KEY_S)
		data->keys.down = 0;
	else if (keycode == KEY_A || keycode == KEY_Q)
		data->keys.left = 0;
	else if (keycode == KEY_D)
		data->keys.right = 0;
	else if (keycode == KEY_LEFT)
		data->keys.rot_left = 0;
	else if (keycode == KEY_RIGHT)
		data->keys.rot_right = 0;
	return (0);
}
