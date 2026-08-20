/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:00:58 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 16:34:37 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

char	*shift_str(char *str, int n)
{
	while (is_space(*str))
		str++;
	str += n;
	while (is_space(*str))
		str++;
	return (str);
}

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
