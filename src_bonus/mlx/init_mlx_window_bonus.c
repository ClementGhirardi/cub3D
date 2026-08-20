/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_window_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 12:27:27 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/15 21:11:19 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	init_mlx_window(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (error_msg("MLX initialization failed"));
	data->mlx.win = mlx_new_window(data->mlx.mlx,
			WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->mlx.win)
		return (error_msg("Window creation failed"));
	mlx_mouse_hide(data->mlx.mlx, data->mlx.win);
	mlx_mouse_move(data->mlx.mlx, data->mlx.win,
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
