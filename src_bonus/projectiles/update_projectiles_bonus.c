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
		if (hit_obstacle(data, x, y, 1))
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
