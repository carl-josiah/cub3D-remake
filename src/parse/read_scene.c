/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:13:56 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/02 21:19:53 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

static int	open_fd(const char *file_path, int *fd)
{
	*fd = open(file_path, O_RDONLY);
	if (*fd < 0)
		return (0);
	return (1);
}

static size_t	count_lines(int fd)
{
	size_t	line_count;
	char	*line;

	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		++line_count;
	}
	free(line);
	return (line_count);
}

static int	allocate_lines_ptr(t_game *game)
{
	game->conf.file.lines = ft_calloc(game->conf.file.line_count + 1,
			sizeof(*game->conf.file.lines));
	if (!game->conf.file.lines)
		return (0);
	return (1);
}

static int	allocate_lines(t_game *game, int fd)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (i < game->conf.file.line_count)
	{
		game->conf.file.lines[i] = get_next_line(fd);
		if (!game->conf.file.lines[i])
		{
			tmp = get_next_line(fd);
			if (!tmp)
				return (0);
			free(tmp);
			return (0);
		}
		++i;
	}
	tmp = get_next_line(fd);
	if (!tmp)
		return (1);
	free(tmp);
	return (1);
}

void	read_scene(t_game *game, const char *file_path)
{
	int	fd;

	if (!open_fd(file_path, &fd))
		error_system(game, ERROR_OPEN);
	game->conf.file.line_count = count_lines(fd);
	close(fd);
	if (!allocate_lines_ptr(game))
		error_system(game, ERROR_CALLOC);
	if (!open_fd(file_path, &fd))
		error_system(game, ERROR_OPEN);
	if (!allocate_lines(game, fd))
		error_system(game, ERROR_MALLOC);
	close(fd);
}
