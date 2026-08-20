/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:01:57 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 11:53:15 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	init_data(t_data *data)
{
	init_config(data);
	init_map(data);
	init_keys(data);
	init_player(data);
	init_mlx(data);
	init_sprites(data);
	init_doors(data);
}
