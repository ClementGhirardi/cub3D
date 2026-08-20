/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:38:41 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 12:06:04 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	parse_component(char **str, int *value)
{
	int	n;

	while (is_space(**str))
		(*str)++;
	if (!(**str >= '0' && **str <= '9'))
		return (1);
	n = 0;
	while (**str >= '0' && **str <= '9')
	{
		n = n * 10 + (**str - '0');
		if (n > 255)
			return (1);
		(*str)++;
	}
	*value = n;
	return (0);
}

static void	skip_spaces(char **str)
{
	while (is_space(**str))
		(*str)++;
}

static int	parse_rgb(char *str, t_rgb *rgb)
{
	if (parse_component(&str, &rgb->r))
		return (1);
	skip_spaces(&str);
	if (*str != ',')
		return (1);
	str++;
	if (parse_component(&str, &rgb->g))
		return (1);
	skip_spaces(&str);
	if (*str != ',')
		return (1);
	str++;
	if (parse_component(&str, &rgb->b))
		return (1);
	skip_spaces(&str);
	if (*str)
		return (1);
	return (0);
}

static int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	parse_color(t_data *data, char *line, t_line_type type)
{
	t_rgb	rgb;
	char	*ptr;
	int		color;

	ptr = line;
	ptr = shift_str(ptr, 1);
	if (parse_rgb(ptr, &rgb))
		return (error_msg("Invalid color"));
	color = rgb_to_int(rgb.r, rgb.g, rgb.b);
	if (type == LINE_F)
	{
		if (data->config.floor_color != -1)
			return (error_msg("Duplicate floor color"));
		data->config.floor_color = color;
	}
	else if (type == LINE_C)
	{
		if (data->config.ceiling_color != -1)
			return (error_msg("Duplicate ceiling color"));
		data->config.ceiling_color = color;
	}
	return (0);
}
