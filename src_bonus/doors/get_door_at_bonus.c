/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_at_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 09:54:37 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 10:03:10 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

t_door	*get_door_at(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (i < data->doors.count)
	{
		if (data->doors.list[i].x == x
			&& data->doors.list[i].y == y)
			return (&data->doors.list[i]);
		i++;
	}
	return (NULL);
}
