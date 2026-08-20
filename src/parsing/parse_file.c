/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 20:08:54 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 13:56:02 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_extension(char *filename)
{
	size_t	len;

	if (!filename)
		return (1);
	len = ft_strlen(filename);
	if (len <= 4)
		return (1);
	if (ft_strncmp((filename + len - 4), ".cub", 4))
		return (1);
	return (0);
}

static void	init_parse(t_parse *parse)
{
	parse->lines = NULL;
	parse->line_count = 0;
	parse->map_start = -1;
}

static void	free_parse(t_parse *parse)
{
	int	i;

	if (!parse->lines)
		return ;
	i = 0;
	while (parse->lines[i])
	{
		free(parse->lines[i]);
		i++;
	}
	free(parse->lines);
	parse->lines = NULL;
}

int	parse_file(t_data *data, char *filename)
{
	t_parse	parse;

	if (check_extension(filename))
		return (error_msg("Invalid map extension"));
	init_parse(&parse);
	if (read_file_lines(filename, &parse))
		return (free_parse(&parse), 1);
	if (parse_config(data, &parse))
		return (free_parse(&parse), 1);
	if (extract_map(data, &parse))
		return (free_parse(&parse), 1);
	if (validate_map(data))
		return (free_parse(&parse), 1);
	free_parse(&parse);
	return (0);
}
