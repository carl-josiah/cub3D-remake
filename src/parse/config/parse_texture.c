/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:34:26 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/08 17:14:35 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse.h"

static void	extract_texture(t_game *game, char *line, t_scene_id id)
{
	const t_scene_id	ids[4] = {TEX_NORTH, TEX_SOUTH, TEX_WEST, TEX_EAST};
	const int			p[4] = {PATH_NORTH, PATH_SOUTH, PATH_WEST, PATH_EAST};
	int					i;
	int					fd;

	i = 0;
	fd = 0;
	while (i < TEX_COUNT)
	{
		if ((id & ids[i]) == ids[i])
		{
			game->conf.tex.paths[p[i]] = ft_strtrim(line, SPACES);
			if (!game->conf.tex.paths[p[i]])
				error_system(game, ERROR_MALLOC, game->conf.tex.paths[p[i]]);
			if (!open_fd(game->conf.tex.paths[p[i]], &fd))
				error_system(game, ERROR_OPEN, game->conf.tex.paths[p[i]]);
			close(fd);
			return ;
		}
		++i;
	}
}

void	parse_texture(t_game *game, char *line, t_scene_id id)
{
	count_and_skip(game, &line, id);
	if ((id & TEX_NORTH) == TEX_NORTH)
		extract_texture(game, line, id);
	else if ((id & TEX_SOUTH) == TEX_SOUTH)
		extract_texture(game, line, id);
	else if ((id & TEX_WEST) == TEX_WEST)
		extract_texture(game, line, id);
	else if ((id & TEX_EAST) == TEX_EAST)
		extract_texture(game, line, id);
}
