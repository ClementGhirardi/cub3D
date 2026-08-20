/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:23:11 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 12:04:42 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

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

static int	fill_config_texture(t_texture *texture, char **path, char *err_msg)
{
	if (texture->path)
		return (free(*path), error_msg(err_msg));
	texture->path = *path;
	return (0);
}

static int	fill_data_texture(t_data *data, t_line_type type, char *path)
{
	int	err;

	err = 0;
	if (type == LINE_NO)
		err = fill_config_texture(&data->config.north, &path,
				"Duplicate NO texture");
	if (type == LINE_SO)
		err = fill_config_texture(&data->config.south, &path,
				"Duplicate SO texture");
	if (type == LINE_WE)
		err = fill_config_texture(&data->config.west, &path,
				"Duplicate WE texture");
	if (type == LINE_EA)
		err = fill_config_texture(&data->config.east, &path,
				"Duplicate EA texture");
	if (type == LINE_DO)
		err = fill_config_texture(&data->config.door, &path,
				"Duplicate DO texture");
	return (err);
}

int	parse_texture(t_data *data, char *line, t_line_type type)
{
	char	*path;

	if (type != LINE_NO && type != LINE_SO
		&& type != LINE_WE && type != LINE_EA
		&& type != LINE_DO)
		return (error_msg("Invalid texture type"));
	path = extract_path(line);
	if (!path)
		return (error_msg("Invalid texture path"));
	if (fill_data_texture(data, type, path))
		return (1);
	return (0);
}
