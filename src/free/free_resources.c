/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 10:34:47 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/02 21:51:34 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/free.h"

static void	free_parser(t_config *conf)
{
	if (conf->file.lines)
		ft_free_str_array(&conf->file.lines);
}

void	free_resources(t_game *game)
{
	free_parser(&game->conf);
}
