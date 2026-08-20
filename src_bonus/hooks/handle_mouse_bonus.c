/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 12:46:06 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 01:57:21 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	handle_mouse(int x, int y, t_data *data)
{
	int	center_x;
	int	center_y;
	int	delta_x;

	center_x = WIN_WIDTH / 2;
	center_y = WIN_HEIGHT / 2;
	if (x == center_x && y == center_y)
		return (0);
	delta_x = x - center_x;
	if (delta_x != 0)
		rotate_player(data, delta_x * MOUSE_SENS);
	mlx_mouse_move(data->mlx.mlx, data->mlx.win,
		center_x, center_y);
	mlx_do_sync(data->mlx.mlx);
	return (0);
}
