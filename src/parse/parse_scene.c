/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:53:20 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/08 17:13:55 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

static void	handle_line(t_game *game, char *line, t_state state)
{
	if (!game || !line || (state < 0 || state > 1))
		return ;
	if (state == STATE_CONFIG)
		parse_config(game, line, &game->conf);
	else if (state == STATE_MAP)
		parse_map(game, line, &game->map);
}

static int	is_line_empty(char *line)
{
	if (!line)
		return (0);
	while (*line && ft_isspace(*line))
		line++;
	if (*line)
		return (0);
	return (1);
}

static void	identify_state(char *line, int bits, t_state *state)
{
	if (!line || state == NULL)
		return ;
	if (*state == STATE_MAP)
		return ;
	while (*line && ft_isspace(*line))
		line++;
	if (!ft_strncmp("WE", line, 2) && ft_isspace(line[2]))
		*state = STATE_CONFIG;
	else if (ft_str_has_charset(line, MAP) && (bits & ID_ALL) == ID_ALL)
		*state = STATE_MAP;
}

void	parse_scene(t_game *game, const char *file_path)
{
	size_t	i;
	t_state	state;

	if (!game || !file_path)
		return ;
	read_scene(game, file_path);
	if (!game->conf.file.lines || !*game->conf.file.lines)
		error_parse(game, ERROR_EMPTY, NULL);
	i = 0;
	state = STATE_CONFIG;
	while (i < game->conf.file.line_count)
	{
		if (!is_line_empty(game->conf.file.lines[i]))
		{
			identify_state(game->conf.file.lines[i], game->conf.bits, &state);
			handle_line(game, game->conf.file.lines[i], state);
		}
		++i;
	}
}
