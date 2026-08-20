/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:01:57 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 11:53:07 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	free_data(t_data *data)
{
	destroy_mlx(data);
	free_sprites(data);
	free_doors(data);
	free_config(&data->config);
	free_map(&data->map);
}
