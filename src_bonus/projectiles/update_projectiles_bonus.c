/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_projectiles_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 14:45:04 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/31 16:19:01 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	hit_sprite(t_data *data, double x, double y)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->sprites.count)
	{
		if (fabs(data->sprites.list[i].x - x)
			< data->sprites.hit_box[data->sprites.current_frame] / 2
			&& fabs(data->sprites.list[i].y - y)
			< data->sprites.hit_box[data->sprites.current_frame] / 2)
		{
			j = 0;
			while (j < data->sprites.count)
			{
				if ((int)data->sprites.list[j].x == (int)x
					&& (int)data->sprites.list[j].y == (int)y)
					return (data->sprites.list[j].active = 0, 1);
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	hit_obstacle(t_data *data, double x, double y)
{
	int		map_x;
	int		map_y;
	t_door	*door;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0
		|| map_x >= data->map.width
		|| map_y >= data->map.height)
		return (1);
	if (data->map.grid[map_y][map_x] == '1'
		|| hit_sprite(data, x, y))
		return (1);
	door = get_door_at(data, map_x, map_y);
	if (door && door->progress < DOOR_WALKABLE)
		return (1);
	return (0);
}

static void	move_projectile(t_data *data, t_projectile *p)
{
	double	step;
	double	x;
	double	y;
	int		i;

	step = PROJECTILE_SPEED / 4.0;
	i = 0;
	while (i < 4)
	{
		x = p->x + p->dir_x * step;
		y = p->y + p->dir_y * step;
		if (hit_obstacle(data, x, y))
		{
			p->state = PROJECTILE_EXPLODING;
			p->explosion_frame = 0;
			p->explosion_counter = 0;
			return ;
		}
		p->x = x;
		p->y = y;
		i++;
	}
}

static void	update_explosion(t_projectile *p)
{
	p->explosion_counter++;
	if (p->explosion_counter >= EXPLOSION_ANIM_SPEED)
	{
		p->explosion_counter = 0;
		p->explosion_frame++;
	}
	if (p->explosion_frame >= EXPLOSION_FRAMES)
		p->active = 0;
}

void	update_projectiles(t_data *data)
{
	int				i;
	t_projectile	*p;

	i = 0;
	while (i < MAX_PROJECTILES)
	{
		p = &data->projectiles.list[i];
		if (p->active)
		{
			if (p->state == PROJECTILE_FLYING)
				move_projectile(data, p);
			else if (p->state == PROJECTILE_EXPLODING)
				update_explosion(p);
		}
		i++;
	}
}
