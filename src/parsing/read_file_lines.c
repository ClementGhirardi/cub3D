/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:07:04 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/15 12:57:20 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_file_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	remove_newline(char *line)
{
	size_t	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	read_file_lines(char *filename, t_parse *parse)
{
	int		fd;
	int		i;

	parse->line_count = count_file_lines(filename);
	if (parse->line_count == -1)
		return (error_msg("Could not open the file"));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_msg("Could not open the file"));
	parse->lines = malloc((parse->line_count + 1) * sizeof(char *));
	if (!parse->lines)
		return (close(fd), error_msg("Malloc failed"));
	i = 0;
	parse->lines[i] = get_next_line(fd);
	while (parse->lines[i])
	{
		remove_newline(parse->lines[i]);
		i++;
		parse->lines[i] = get_next_line(fd);
	}
	parse->lines[i] = NULL;
	if (i != parse->line_count)
		return (close(fd), error_msg("GNL failed"));
	close(fd);
	return (0);
}
