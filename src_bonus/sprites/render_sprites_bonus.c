/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:38:43 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 00:42:33 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	transform_sprite(t_data *data,
		t_sprite *sprite, t_sprite_render *render)
{
	render->x = sprite->x - data->player.x;
	render->y = sprite->y - data->player.y;
	render->inv_det = 1.0
		/ (data->player.plane_x * data->player.dir_y
			- data->player.dir_x * data->player.plane_y);
	render->transform_x = render->inv_det
		* (data->player.dir_y * render->x
			- data->player.dir_x * render->y);
	render->transform_y = render->inv_det
		* (-data->player.plane_y * render->x
			+ data->player.plane_x * render->y);
}

static void	init_sprite_bounds(t_sprite_render *render)
{
	render->height = abs((int)(WIN_HEIGHT / render->transform_y));
	render->start_y = -render->height / 2 + WIN_HEIGHT / 2;
	if (render->start_y < 0)
		render->start_y = 0;
	render->end_y = render->height / 2 + WIN_HEIGHT / 2;
	if (render->end_y >= WIN_HEIGHT)
		render->end_y = WIN_HEIGHT - 1;
	render->width = render->height;
	render->start_x = -render->width / 2 + render->screen_x;
	if (render->start_x < 0)
		render->start_x = 0;
	render->end_x = render->width / 2 + render->screen_x;
	if (render->end_x >= WIN_WIDTH)
		render->end_x = WIN_WIDTH - 1;
}

void	render_sprites(t_data *data)
{
	t_sprite_render	render;
	t_sprite		*sprite;
	int				i;

	sort_sprites(data);
	i = 0;
	while (i < data->sprites.count)
	{
		sprite = &data->sprites.list[i];
		transform_sprite(data, sprite, &render);
		if (render.transform_y > 0)
		{
			render.screen_x = (int)((WIN_WIDTH / 2)
					* (1 + render.transform_x / render.transform_y));
			init_sprite_bounds(&render);
			draw_sprite(data, &render);
		}
		i++;
	}
}
