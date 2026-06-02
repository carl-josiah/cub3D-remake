/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_system.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 12:10:34 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/01 11:06:20 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"

void	error_system(t_game *game, char *context)
{
	if (game)
		free_resources(game);
	write(STDERR_FILENO, "Error\n", 6);
	perror(context);
	exit(EXIT_FAILURE);
}
