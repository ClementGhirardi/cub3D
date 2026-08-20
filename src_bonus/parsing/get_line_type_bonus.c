/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_type_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:00:58 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 12:03:03 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	is_map_char(char c)
{
	return (c == '0'
		|| c == '1'
		|| c == 'N'
		|| c == 'S'
		|| c == 'W'
		|| c == 'E'
		|| c == 'D'
		|| c == '2');
}

t_line_type	get_line_type(char *line)
{
	if (!line)
		return (LINE_INVALID);
	while (is_space(*line))
		line++;
	if (!*line)
		return (LINE_EMPTY);
	else if (!ft_strncmp(line, "NO", 2) && is_space(line[2]))
		return (LINE_NO);
	else if (!ft_strncmp(line, "SO", 2) && is_space(line[2]))
		return (LINE_SO);
	else if (!ft_strncmp(line, "WE", 2) && is_space(line[2]))
		return (LINE_WE);
	else if (!ft_strncmp(line, "EA", 2) && is_space(line[2]))
		return (LINE_EA);
	else if (!ft_strncmp(line, "DO", 2) && is_space(line[2]))
		return (LINE_DO);
	else if (*line == 'F' && is_space(line[1]))
		return (LINE_F);
	else if (*line == 'C' && is_space(line[1]))
		return (LINE_C);
	else if (is_map_char(*line))
		return (LINE_MAP);
	return (LINE_INVALID);
}
