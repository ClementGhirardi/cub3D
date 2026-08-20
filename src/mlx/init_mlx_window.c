/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 12:27:27 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/14 13:09:04 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_mlx_window(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (error_msg("MLX initialization failed"));
	data->mlx.win = mlx_new_window(data->mlx.mlx,
			WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->mlx.win)
		return (error_msg("Window creation failed"));
	return (0);
}
