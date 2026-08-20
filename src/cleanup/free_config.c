/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement-ghirardi <clement-ghirardi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 11:44:02 by clement-ghi       #+#    #+#             */
/*   Updated: 2026/08/19 13:05:16 by clement-ghi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_config(t_config *config)
{
	free(config->north.path);
	free(config->south.path);
	free(config->west.path);
	free(config->east.path);
	config->north.path = NULL;
	config->south.path = NULL;
	config->west.path = NULL;
	config->east.path = NULL;
}
