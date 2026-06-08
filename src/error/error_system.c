/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_system.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 12:10:34 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/07 14:58:17 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"

void	error_system(t_game *game, const char *context, const char *line)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (context)
	{
		write(STDERR_FILENO, context, ft_strlen(context));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, strerror(errno), ft_strlen(strerror(errno)));
	}
	if (line)
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, line, ft_strlen(line));
	}
	if (context || line)
		write(STDERR_FILENO, "\n", 1);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}
