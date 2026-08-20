/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:38:43 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 00:38:41 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	update_sprite_distances(t_data *data)
{
	double	dx;
	double	dy;
	int		i;

	i = 0;
	while (i < data->sprites.count)
	{
		dx = data->sprites.list[i].x - data->player.x;
		dy = data->sprites.list[i].y - data->player.y;
		data->sprites.list[i].distance = dx * dx + dy * dy;
		i++;
	}
}

static void	swap_sprites(t_sprite *a, t_sprite *b)
{
	t_sprite	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_sprites(t_data *data)
{
	int	i;
	int	j;

	update_sprite_distances(data);
	i = 0;
	while (i < data->sprites.count - 1)
	{
		j = 0;
		while (j < data->sprites.count - i - 1)
		{
			if (data->sprites.list[j].distance
				< data->sprites.list[j + 1].distance)
			{
				swap_sprites(&data->sprites.list[j],
					&data->sprites.list[j + 1]);
			}
			j++;
		}
		i++;
	}
}
