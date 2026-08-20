/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 13:08:29 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 01:36:27 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	get_door_in_front(t_data *data, int *door_x, int *door_y)
{
	double	check_x;
	double	check_y;
	double	dist;

	dist = 0.2;
	while (dist <= DOOR_REACH)
	{
		check_x = data->player.x + data->player.dir_x * dist;
		check_y = data->player.y + data->player.dir_y * dist;
		*door_x = (int)check_x;
		*door_y = (int)check_y;
		if (data->map.grid[*door_y][*door_x] == 'D')
			return (1);
		if (data->map.grid[*door_y][*door_x] == '1')
			return (0);
		dist += 0.1;
	}
	return (0);
}

void	open_door(t_data *data)
{
	int		x;
	int		y;
	t_door	*door;

	if (!get_door_in_front(data, &x, &y))
		return ;
	door = get_door_at(data, x, y);
	if (!door)
		return ;
	if (door->state == DOOR_CLOSED
		|| door->state == DOOR_CLOSING)
		door->state = DOOR_OPENING;
	else if (door->state == DOOR_OPEN
		|| door->state == DOOR_OPENING)
		door->state = DOOR_CLOSING;
}
