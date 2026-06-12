/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:53:20 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/11 14:37:54 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

static void	count_map_lines(t_map *map, char **lines, int *count_lines)
{
	++map->grid.size.y;
	*count_lines = 0;
}

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
		++line;
	if (!ft_strncmp("WE", line, 2) && ft_isspace(line[2]))
		*state = STATE_CONFIG;
	if (ft_str_has_charset(line, MAP) && ((bits & ID_ALL) == ID_ALL))
		*state = STATE_MAP;
}

static int	is_file_spaces(char **lines, size_t line_count)
{
	size_t	i;

	i = 0;
	if (!lines || !*lines)
		return (1);
	while (is_line_empty(lines[i]))
		++i;
	if (line_count == i)
		return (1);
	return (0);
}

void	parse_scene(t_game *game, const char *file_path)
{
	size_t	i;
	t_state	state;
	int		count;

	if (!game || !file_path)
		return ;
	read_scene(game, file_path);
	if (!game->conf.file.lines || !*game->conf.file.lines)
		error_parse(game, ERROR_EMPTY, NULL);
	if (is_file_spaces(game->conf.file.lines, game->conf.file.line_count))
		error_parse(game, ERROR_EMPTY, NULL);
	i = 0;
	state = STATE_CONFIG;
	count = 1;
	while (i < game->conf.file.line_count)
	{
		if (!is_line_empty(game->conf.file.lines[i]))
		{
			identify_state(game->conf.file.lines[i], game->conf.bits, &state);
			// if (state == STATE_MAP && count)
			handle_line(game, game->conf.file.lines[i], state);
		}
		++i;
	}
	printf("%zu\n", game->conf.file.line_count);
}
