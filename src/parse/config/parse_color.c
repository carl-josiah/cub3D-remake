/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:58:49 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/11 14:27:02 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse.h"

static int	is_number(char *line, size_t *i, size_t *number_count)
{
	size_t	digit_len;

	digit_len = 0;
	while (line[*i])
	{
		while (line[*i] == '0')
			++(*i);
		if (ft_isdigit(line[*i]))
		{
			++(*i);
			++digit_len;
		}
		else
			break ;
	}
	if (digit_len > 3 || digit_len == 0)
		return (0);
	if (number_count)
		(*number_count)++;
	return (1);
}

static int	is_comma(char c, size_t *i, size_t *comma_count)
{
	if (c == ',')
	{
		++(*i);
		if (comma_count)
			++(*comma_count);
		return (1);
	}
	return (0);
}

static int	validate_structure(char *line)
{
	size_t	i;
	size_t	comma_count;
	size_t	number_count;

	if (!line || !*line)
		return (0);
	i = 0;
	comma_count = 0;
	number_count = 0;
	while (number_count < 3)
	{
		if (!is_number(line, &i, &number_count))
			return (0);
		if (comma_count < 2)
		{
			if (!is_comma(line[i], &i, &comma_count))
				return (0);
		}
	}
	if (number_count != 3 || comma_count != 2)
		return (0);
	while (line[i] && ft_isspace(line[i]))
		++i;
	if (line[i])
		return (0);
	return (1);
}

static int	extract_color(char *line, t_col *color, int which_rgb)
{
	size_t	i;
	size_t	num_count;
	int		channel;
	
	if (!line || !color)
		return (0);
	i = 0;
	num_count = 0;
	while (num_count < CHANNEL_COUNT)
	{
		channel = ft_atoi(&line[i]);
		if (!is_number(line, &i, NULL))
			return (0);
		if (num_count < 2)
		{
			if (!is_comma(line[i], &i, NULL))
				return (0);
		}
		identify_color_channel(num_count, channel, color, which_rgb);
		++num_count;
	}
	return (1);
}

void	parse_color(t_game *game, char *line, t_scene_id id)
{
	count_and_skip(game, &line, id);
	if (!validate_structure(line))
		error_parse(game, ERROR_COLOR, NULL);
	if (!is_valid_color_value(line))
		error_parse(game, ERROR_COLOR, NULL);
	if ((id & COL_FLOOR) == COL_FLOOR)
	{
		if (!extract_color(line, &game->conf.col, RGB_FLOOR))
			error_parse(game, ERROR_COLOR, NULL);
	}
	else if ((id & COL_CEILING) == COL_CEILING)
	{
		if (!extract_color(line, &game->conf.col, RGB_CEILING))
			error_parse(game, ERROR_COLOR, NULL);
	}
}
