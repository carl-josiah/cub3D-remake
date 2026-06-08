/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:08:47 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/08 17:09:54 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	open_fd(const char *file_path, int *fd)
{
	if (!file_path || !fd)
		return (0);
	*fd = open(file_path, O_RDONLY);
	if (*fd < 0)
		return (0);
	return (1);
}

void	count_and_skip(t_game *game, char **trimmed, t_scene_id id)
{
	if (!game || !trimmed || !*trimmed)
		return ;
	if (ft_count_words(*trimmed, SPACES) != 2)
		error_parse(game, ERROR_PATH_COUNT, *trimmed);
	if ((id & TEX_ALL) != 0)
		*trimmed += 2;
	else
		*trimmed += 1;
	while (**trimmed && ft_isspace(**trimmed))
		(*trimmed)++;
}
