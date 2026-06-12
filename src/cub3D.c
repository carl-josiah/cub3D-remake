/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:30:13 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/11 14:20:43 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	validate_arguments(ac, av);
	init_game(&game);
	parse_scene(&game, av[1]);
	// validate map
	// init mlx
	// execute raycasting
	// execute rendering
	// execute movement
	// loop mlx
	free_game(&game);
	return (EXIT_SUCCESS);
}
