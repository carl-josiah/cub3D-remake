/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 21:00:41 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/10 18:48:36 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/init.h"

static void	init_config(t_config *conf)
{
	size_t	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		conf->tex.paths[i] = NULL;
		++i;
	}
	i = 0;
	while (i < COL_COUNT)
	{
		conf->col.rgb[i] = 0;
		++i;
	}
	conf->bits = 0;
}

static void	init_file(t_file *file)
{
	file->lines = NULL;
	file->line_count = 0;
}

void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(*game));
	init_file(&game->file);
	init_config(&game->conf);
}
