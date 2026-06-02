/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:53:20 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/02 21:51:10 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

// static int	parse_config(t_game *game)
// {
// 	(void)game;
// 	return (1);
// }

void	parse_scene(t_game *game, const char *file_path)
{
	read_scene(game, file_path);
	// if (!parse_config(game))
	// 	error_parse(game, ERROR_CONFIG);
}
