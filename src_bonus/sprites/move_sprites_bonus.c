/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:34:20 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/09/01 19:37:12 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

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
	{
		*dist_x = s_x * 1e30;
		*dist_y = s_y * 1e30;
	}
	else
	{
		*dist_x = s_x * *dist_x / dist * SPRITE_MOVE_SPEED;
		*dist_y = s_y * *dist_y / dist * SPRITE_MOVE_SPEED;
	}
}

static double	max_dist(double x, double y)
{
	if (fabs(x) < fabs(y))
		return (y);
	return (x);
}

static void	avoid_wall(t_data *data, t_sprite *sprite,
			double dist_x, double dist_y)
{
	double		hit_box;

	hit_box = data->sprites.hit_box[data->sprites.current_frame] / 2;
	if (dist_y < 0)
		dist_y = -SPRITE_MOVE_SPEED;
	else
		dist_y = SPRITE_MOVE_SPEED;
	if (!hit_obstacle(data,
			sprite->x,
			sprite->y + max_dist(dist_y + hit_box, dist_y - hit_box),
			0))
		sprite->y += dist_y;
	if (dist_x < 0)
		dist_x = -SPRITE_MOVE_SPEED;
	else
		dist_x = SPRITE_MOVE_SPEED;
	if (!hit_obstacle(data,
			sprite->x + max_dist(dist_x + hit_box, dist_x - hit_box),
			sprite->y,
			0))
		sprite->x += dist_x;
}

static void	move_sprite(t_data *data, double hit_box, t_sprite *sprite)
{
	double		dist_x;
	double		dist_y;

	if (sprite->active)
	{
		get_sprite_distances(data, sprite, &dist_x, &dist_y);
		if (!hit_obstacle(data, sprite->x + dist_x + hit_box,
				sprite->y + dist_y, 0)
			&& !hit_obstacle(data, sprite->x + dist_x - hit_box,
				sprite->y + dist_y, 0)
			&& !hit_obstacle(data, sprite->x + dist_x,
				sprite->y + dist_y + hit_box, 0)
			&& !hit_obstacle(data, sprite->x + dist_x,
				sprite->y + dist_y - hit_box, 0))
		{
			sprite->y += dist_y;
			sprite->x += dist_x;
		}
		else
			avoid_wall(data, sprite, dist_x, dist_y);
	}
}

void	move_sprites(t_data *data)
{
	t_sprite	*sprite;
	double		hit_box;
	int			i;

	hit_box = data->sprites.hit_box[data->sprites.current_frame] / 2;
	i = 0;
	while (i < data->sprites.count)
	{
		sprite = &data->sprites.list[i];
		move_sprite(data, hit_box, sprite);
		i++;
	}
}
