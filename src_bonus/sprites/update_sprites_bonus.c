/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:54:48 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/31 16:36:52 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	update_anim(t_data *data)
{
	data->sprites.anim_counter++;
	if (data->sprites.anim_counter >= SPRITE_ANIM_SPEED)
	{
		data->sprites.anim_counter = 0;
		data->sprites.current_frame++;
		if (data->sprites.current_frame >= SPRITE_FRAMES)
			data->sprites.current_frame = 0;
	}
}

static void	get_sprite_distances(t_data *data, t_sprite *sprite,
			double *dist_x, double *dist_y)
{
	double	dist;
	int		s_y;
	int		s_x;

	s_x = -1;
	if (sprite->x - data->player.x < 0)
		s_x = 1;
	s_y = -1;
	if (sprite->y - data->player.y < 0)
		s_y = 1;
	*dist_x = fabs(sprite->x - data->player.x);
	*dist_y = fabs(sprite->y - data->player.y);
	dist = sqrt(pow(*dist_x, 2) + pow(*dist_y, 2));
	if (dist == 0)
		dist = 1e30;
	*dist_x = s_x * cos(*dist_x / dist) * SPRITE_MOVE_SPEED;
	*dist_y = s_y * sin(*dist_y / dist) * SPRITE_MOVE_SPEED;
}

static double	max_dist(double x, double y)
{
	if (fabs(x) < fabs(y))
		return (y);
	return (x);
}

static void	move_sprites(t_data *data)
{
	double		hit_box;
	int			i;
	t_sprite	*sprite;
	double		dist_x;
	double		dist_y;

	hit_box = data->sprites.hit_box[data->sprites.current_frame] / 2;
	i = 0;
	while (i < data->sprites.count)
	{
		sprite = &data->sprites.list[i];
		if (sprite->active)
		{
			get_sprite_distances(data, sprite, &dist_x, &dist_y);
			if (!hit_obstacle(data,
					sprite->x + max_dist(dist_x + hit_box, dist_x - hit_box),
					sprite->y + max_dist(dist_y + hit_box, dist_y - hit_box)
				))
			{
				sprite->y += dist_y;
				sprite->x += dist_x;
			}
		}
		i++;
	}
}

void	update_sprites(t_data *data)
{
	update_anim(data);
	move_sprites(data);
}
