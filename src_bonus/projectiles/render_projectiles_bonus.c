/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_projectiles_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 14:45:04 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/21 16:57:26 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	get_explosion_color(t_projectile *p)
{
	if (p->state == PROJECTILE_FLYING)
		return (0xFFFF00);
	if (p->explosion_frame <= 1)
		return (0xFFFFFF);
	if (p->explosion_frame <= 3)
		return (0xFF8800);
	return (0xFF2200);
}

static void	draw_projectile_circle(t_data *data,
	t_sprite_render *r, t_projectile *p)
{
	int	x;
	int	y;
	int	center_x;
	int	center_y;
	int	radius;

	center_x = r->screen_x;
	center_y = WIN_HEIGHT / 2;
	radius = r->width / 2;
	y = center_y - radius;
	while (y <= center_y + radius)
	{
		x = center_x - radius;
		while (x <= center_x + radius)
		{
			if (pow(x - center_x, 2) + pow(y - center_y, 2) <= radius * radius
				&& x >= 0 && x < WIN_WIDTH
				&& y >= 0 && y < WIN_HEIGHT
				&& r->transform_y < data->sprites.z_buffer[x]
				&& r->transform_y < data->sprites.sprite_z_buffer[x])
				put_pixel(&data->mlx.frame, x, y, get_explosion_color(p));
			x++;
		}
		y++;
	}
}

static int	init_projectile_bounds(t_data *data,
		t_projectile *p, t_sprite_render	*r)
{
	double			sprite_x;
	double			sprite_y;

	sprite_x = p->x - data->player.x;
	sprite_y = p->y - data->player.y;
	r->inv_det = 1.0 / (data->player.plane_x * data->player.dir_y
			- data->player.dir_x * data->player.plane_y);
	r->transform_x = r->inv_det * (data->player.dir_y * sprite_x
			- data->player.dir_x * sprite_y);
	r->transform_y = r->inv_det * (-data->player.plane_y * sprite_x
			+ data->player.plane_x * sprite_y);
	if (r->transform_y <= 0.0)
		return (1);
	r->screen_x = (int)((WIN_WIDTH / 2)
			* (1 + r->transform_x / r->transform_y));
	return (0);
}

static void	draw_projectile(t_data *data, t_projectile *p)
{
	t_sprite_render	r;

	if (init_projectile_bounds(data, p, &r))
		return ;
	if (p->state == PROJECTILE_FLYING)
		r.width = abs((int)(WIN_HEIGHT / r.transform_y)) / 16;
	else
		r.width = abs((int)(WIN_HEIGHT / r.transform_y))
			* (p->explosion_frame + 1) / 16;
	if (r.width < 2)
		r.width = 2;
	if (r.width > 200)
		r.width = 200;
	draw_projectile_circle(data, &r, p);
}

void	render_projectiles(t_data *data)
{
	int	i;

	i = 0;
	while (i < MAX_PROJECTILES)
	{
		if (data->projectiles.list[i].active)
			draw_projectile(data, &data->projectiles.list[i]);
		i++;
	}
}
