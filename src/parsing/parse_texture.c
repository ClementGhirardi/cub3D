/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:23:11 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 13:14:31 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*extract_path(char *line)
{
	int	start;
	int	len;

	line = shift_str(line, 2);
	if (!*line)
		return (NULL);
	start = 0;
	while (line[start] && !is_space(line[start]))
		start++;
	len = start;
	while (line[start] && is_space(line[start]))
		start++;
	if (line[start])
		return (NULL);
	return (ft_substr(line, 0, len));
}

static int	fill_data_texture(t_data *data, t_line_type type,
	char *path)
{
	if (type == LINE_NO)
	{
		if (data->config.north.path)
			return (free(path), error_msg("Duplicate NO texture"));
		data->config.north.path = path;
	}
	else if (type == LINE_SO)
	{
		if (data->config.south.path)
			return (free(path), error_msg("Duplicate SO texture"));
		data->config.south.path = path;
	}
	else if (type == LINE_WE)
	{
		if (data->config.west.path)
			return (free(path), error_msg("Duplicate WE texture"));
		data->config.west.path = path;
	}
	else if (type == LINE_EA)
	{
		if (data->config.east.path)
			return (free(path), error_msg("Duplicate EA texture"));
		data->config.east.path = path;
	}
	return (0);
}

int	parse_texture(t_data *data, char *line, t_line_type type)
{
	char	*path;

	if (type != LINE_NO && type != LINE_SO
		&& type != LINE_WE && type != LINE_EA)
		return (error_msg("Invalid texture type"));
	path = extract_path(line);
	if (!path)
		return (error_msg("Invalid texture path"));
	if (fill_data_texture(data, type, path))
		return (1);
	return (0);
}
