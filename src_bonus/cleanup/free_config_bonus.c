/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_config_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 11:44:02 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/18 11:44:29 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	free_config(t_config *config)
{
	free(config->north.path);
	free(config->south.path);
	free(config->west.path);
	free(config->east.path);
	free(config->door.path);
	config->north.path = NULL;
	config->south.path = NULL;
	config->west.path = NULL;
	config->east.path = NULL;
	config->door.path = NULL;
}
