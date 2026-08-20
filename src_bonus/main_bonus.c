/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:25:18 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 18:16:34 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	game_loop(t_data *data)
{
	if (data->keys.up)
		move_player(data, 1.0);
	if (data->keys.down)
		move_player(data, -1.0);
	if (data->keys.left)
		strafe_player(data, -1.0);
	if (data->keys.right)
		strafe_player(data, 1.0);
	if (data->keys.rot_left)
		rotate_player(data, -ROT_SPEED);
	if (data->keys.rot_right)
		rotate_player(data, ROT_SPEED);
	update_doors(data);
	update_sprites(data);
	render_frame(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx.mlx,
		data->mlx.win, data->mlx.frame.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (argc != 2)
		return (error_msg("Invalid number of arguments"));
	if (parse_file(&data, argv[1]))
		return (free_data(&data), 1);
	if (init_mlx_window(&data))
		return (free_data(&data), 1);
	if (init_frame(&data))
		return (free_data(&data), 1);
	if (load_textures(&data))
		return (free_data(&data), 1);
	if (load_sprites(&data))
		return (free_data(&data), 1);
	init_hooks(&data);
	mlx_loop_hook(data.mlx.mlx, game_loop, &data);
	mlx_loop(data.mlx.mlx);
	free_data(&data);
	return (0);
}
