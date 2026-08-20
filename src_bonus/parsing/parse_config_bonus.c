/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:30:31 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 11:58:28 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	parse_config_line(t_data *data, char *line)
{
	t_line_type	type;

	type = get_line_type(line);
	if (type == LINE_EMPTY)
		return (0);
	if (type == LINE_NO || type == LINE_SO
		|| type == LINE_WE || type == LINE_EA
		|| type == LINE_DO)
		return (parse_texture(data, line, type));
	if (type == LINE_F || type == LINE_C)
		return (parse_color(data, line, type));
	return (0);
}

static int	config_is_complete(t_data *data)
{
	if (!data->config.north.path
		|| !data->config.south.path
		|| !data->config.west.path
		|| !data->config.east.path
		|| !data->config.door.path)
		return (0);
	if (data->config.floor_color == -1
		|| data->config.ceiling_color == -1)
		return (0);
	return (1);
}

int	parse_config(t_data *data, t_parse *parse)
{
	t_line_type	type;
	int			i;

	i = 0;
	while (parse->lines[i])
	{
		type = get_line_type(parse->lines[i]);
		if ((type == LINE_NO || type == LINE_SO
				|| type == LINE_WE || type == LINE_EA
				|| type == LINE_DO || type == LINE_F || type == LINE_C)
			&& parse_config_line(data, parse->lines[i]))
			return (1);
		else if (type == LINE_MAP)
		{
			if (!config_is_complete(data))
				return (error_msg("Incomplete configuration"));
			parse->map_start = i;
			return (0);
		}
		else if (type == LINE_INVALID)
			return (error_msg("Invalid configuration line"));
		i++;
	}
	return (error_msg("Missing map"));
}
