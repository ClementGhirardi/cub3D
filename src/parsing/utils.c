/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:09:40 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 13:14:54 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	return (c == 'N' || c == 'S'
		|| c == 'E' || c == 'W');
}
