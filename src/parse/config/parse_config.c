/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:43:55 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/08 17:16:14 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse.h"

static t_scene_id	identify_id(char *line)
{
	if (!ft_strncmp("NO", line, 2) && ft_isspace(line[2]))
		return (TEX_NORTH);
	if (!ft_strncmp("SO", line, 2) && ft_isspace(line[2]))
		return (TEX_SOUTH);
	if (!ft_strncmp("WE", line, 2) && ft_isspace(line[2]))
		return (TEX_WEST);
	if (!ft_strncmp("EA", line, 2) && ft_isspace(line[2]))
		return (TEX_EAST);
	if (!ft_strncmp("F", line, 1) && ft_isspace(line[1]))
		return (COL_FLOOR);
	if (!ft_strncmp("C", line, 1) && ft_isspace(line[1]))
		return (COL_CEILING);
	return (0);
}

void	parse_config(t_game *game, char *line, t_config *config)
{
	t_scene_id	id;

	while (*line && ft_isspace(*line))
		line++;
	id = identify_id(line);
	if (!id)
		error_parse(game, ERROR_ID, line);
	if ((config->bits & id) != 0)
		error_parse(game, ERROR_DUP, line);
	if ((id & TEX_ALL) != 0)
		parse_texture(game, line, id);
	else if ((id & COL_ALL) != 0)
		parse_color(game, line, id);
	config->bits |= id;
}
