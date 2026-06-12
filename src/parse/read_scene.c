/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:13:56 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/07 15:16:24 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

static size_t	count_lines(int fd)
{
	size_t	line_count;
	char	*line;

	line_count = 0;
	if (fd < 0)
		return (0);
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
	if (!game)
		return (0);
	game->file.lines = ft_calloc(game->file.line_count + 1,
			sizeof(*game->file.lines));
	if (!game->file.lines)
		return (0);
	return (1);
}

static int	allocate_lines(t_game *game, int fd)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!game || fd < 0)
		return (0);
	while (i < game->file.line_count)
	{
		game->file.lines[i] = get_next_line(fd);
		if (!game->file.lines[i])
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

	if (!game || !file_path)
		return ;
	if (!open_fd(file_path, &fd))
		error_system(game, ERROR_OPEN, file_path);
	game->file.line_count = count_lines(fd);
	close(fd);
	if (!allocate_lines_ptr(game))
		error_system(game, ERROR_CALLOC, NULL);
	if (!open_fd(file_path, &fd))
		error_system(game, ERROR_OPEN, file_path);
	if (!allocate_lines(game, fd))
		error_system(game, ERROR_MALLOC, NULL);
	close(fd);
}
