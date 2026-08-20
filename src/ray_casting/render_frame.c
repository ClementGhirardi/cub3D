/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 22:30:15 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/20 13:26:36 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_texture	*get_wall_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (&data->config.west);
		return (&data->config.east);
	}
	if (ray->step_y > 0)
		return (&data->config.north);
	return (&data->config.south);
}

static void	init_wall_texture(t_data *data, t_ray *ray, t_texture *texture)
{
	if (ray->side == 0)
		ray->wall_x = data->player.y
			+ ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = data->player.x
			+ ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * texture->img.width);
	if (ray->side == 0 && ray->dir_x > 0)
		ray->tex_x = texture->img.width - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->tex_x = texture->img.width - ray->tex_x - 1;
}

static void	draw_textured_wall(t_data *data, t_ray *ray,
		t_texture *texture, int x)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
	int		y;

	step = (double)texture->img.height / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= texture->img.height)
			tex_y = texture->img.height - 1;
		tex_pos += step;
		color = get_pixel(&texture->img, ray->tex_x, tex_y);
		put_pixel(&data->mlx.frame, x, y, color);
		y++;
	}
}

void	draw_column(t_data *data, t_ray *ray, int x)
{
	t_texture	*texture;
	int			y;

	y = 0;
	while (y < ray->draw_start)
	{
		put_pixel(&data->mlx.frame, x, y,
			data->config.ceiling_color);
		y++;
	}
	texture = get_wall_texture(data, ray);
	init_wall_texture(data, ray, texture);
	draw_textured_wall(data, ray, texture, x);
	y = ray->draw_end + 1;
	while (y < WIN_HEIGHT)
	{
		put_pixel(&data->mlx.frame, x, y,
			data->config.floor_color);
		y++;
	}
}

void	render_frame(t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		cast_ray(data, &ray, x);
		draw_column(data, &ray, x);
		x++;
	}
}
