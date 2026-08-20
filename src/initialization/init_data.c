/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:01:57 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 13:05:21 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_data(t_data *data)
{
	init_config(data);
	init_map(data);
	init_keys(data);
	init_player(data);
	init_mlx(data);
}
