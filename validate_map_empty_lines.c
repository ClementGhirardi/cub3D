/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_empty_lines.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 19:23:15 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/15 13:03:46 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_empty_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	validate_map_empty_lines(t_data *data)
{
	int	i;
	int	empty_found;

	i = 0;
	empty_found = 0;
	while (data->map.grid[i])
	{
		if (is_empty_map_line(data->map.grid[i]))
			empty_found = 1;
		else if (empty_found)
			return (error_msg("Empty line inside map"));
		i++;
	}
	return (0);
}
