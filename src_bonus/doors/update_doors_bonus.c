/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_doors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 09:54:37 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 16:53:09 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	update_opening(t_door *door)
{
	door->progress += DOOR_SPEED;
	if (door->progress >= 1.0)
	{
		door->progress = 1.0;
		door->state = DOOR_OPEN;
	}
}

static double	door_distance(t_data *data, t_door *door)
{
	double	dx;
	double	dy;

	dx = door->x + 0.5 - data->player.x;
	dy = door->y + 0.5 - data->player.y;
	return (sqrt(dx * dx + dy * dy));
}

static int	player_near_door(t_data *data, t_door *door)
{
	double	dx;
	double	dy;

	dx = data->player.x - ((double)door->x + 0.5);
	dy = data->player.y - ((double)door->y + 0.5);
	if (dx * dx + dy * dy < 0.7 * 0.7)
		return (1);
	return (0);
}

static void	update_closing(t_door *door)
{
	door->progress -= DOOR_SPEED;
	if (door->progress <= 0.0)
	{
		door->progress = 0.0;
		door->state = DOOR_CLOSED;
	}
}

void	update_doors(t_data *data)
{
	t_door	*door;
	int		i;

	i = 0;
	while (i < data->doors.count)
	{
		door = &data->doors.list[i];
		if (door->state == DOOR_OPENING)
			update_opening(door);
		else if (door->state == DOOR_OPEN)
		{
			if (door_distance(data, door) > DOOR_PASSED)
				door->state = DOOR_CLOSING;
		}
		else if (door->state == DOOR_CLOSING)
		{
			if (player_near_door(data, door))
				door->state = DOOR_OPENING;
			else
				update_closing(door);
		}
		i++;
	}
}
