/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 19:23:15 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 13:15:22 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S'
		|| c == 'E' || c == 'W');
}

static void	set_player_plane(t_player *player, double x, double y)
{
	player->plane_x = x;
	player->plane_y = y;
}

static void	set_player_direction(t_player *player, char orientation)
{
	if (orientation == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		set_player_plane(player, 0.66, 0.0);
	}
	else if (orientation == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		set_player_plane(player, -0.66, 0.0);
	}
	else if (orientation == 'E')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
		set_player_plane(player, 0.0, 0.66);
	}
	else if (orientation == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
		set_player_plane(player, 0.0, -0.66);
	}
}

int	validate_map_chars(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			if (!is_valid_map_char(data->map.grid[y][x]))
				return (error_msg("Invalid character in map"));
			if (is_player_char(data->map.grid[y][x]))
			{
				data->player.count++;
				data->player.x = x + 0.5;
				data->player.y = y + 0.5;
				set_player_direction(&data->player, data->map.grid[y][x]);
			}
			x++;
		}
		y++;
	}
	if (data->player.count != 1)
		return (error_msg("Invalid number of players"));
	return (0);
}
