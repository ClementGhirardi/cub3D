/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:30:11 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/15 17:12:13 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	init_keys(t_data *data)
{
	data->keys.up = 0;
	data->keys.down = 0;
	data->keys.left = 0;
	data->keys.right = 0;
	data->keys.rot_left = 0;
	data->keys.rot_right = 0;
}
