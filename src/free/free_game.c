/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 10:34:47 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/07 14:35:25 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/free.h"

static void	free_paths(char *paths[])
{
	size_t	i;

	i = 0;
	if (paths)
	{
		while (i < TEX_COUNT)
		{
			if (paths[i])
				free(paths[i]);
			++i;
		}
	}
}

static void	free_parser(t_config *conf)
{
	if (conf->file.lines)
		ft_free_str_array(&conf->file.lines);
}

void	free_game(t_game *game)
{
	free_parser(&game->conf);
	free_paths(game->conf.tex.paths);
}
