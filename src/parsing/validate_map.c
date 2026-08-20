/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 20:05:32 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 13:09:51 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	replace_player_by_floor(t_data *data)
{
	int	x;
	int	y;

	x = (int)data->player.x;
	y = (int)data->player.y;
	data->map.grid[y][x] = '0';
}

int	validate_map(t_data *data)
{
	if (validate_map_chars(data))
		return (1);
	if (validate_map_closed(data))
		return (1);
	replace_player_by_floor(data);
	return (0);
}
