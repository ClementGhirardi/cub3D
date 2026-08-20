/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 19:09:25 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/15 17:12:13 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	create_grid(t_data *data, t_parse *parse)
{
	data->map.height = parse->line_count - parse->map_start;
	data->map.grid = malloc((data->map.height + 1) * sizeof(char *));
	if (!data->map.grid)
		return (error_msg("Malloc failed"));
	return (0);
}

int	extract_map(t_data *data, t_parse *parse)
{
	int	i;
	int	j;
	int	width;

	if (parse->map_start < 0)
		return (error_msg("Missing map"));
	if (create_grid(data, parse))
		return (1);
	data->map.grid[0] = NULL;
	i = parse->map_start;
	j = 0;
	width = 0;
	while (parse->lines[i])
	{
		data->map.grid[j] = ft_strdup(parse->lines[i]);
		if (!data->map.grid[j])
			return (free_map(&data->map), error_msg("Malloc failed"));
		data->map.grid[j + 1] = NULL;
		if ((int)ft_strlen(data->map.grid[j]) > width)
			width = (int)ft_strlen(data->map.grid[j]);
		i++;
		j++;
	}
	data->map.width = width;
	return (0);
}
