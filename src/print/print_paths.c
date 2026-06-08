/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 22:58:48 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/07 14:49:54 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/print.h"

void	print_paths(const char *paths[])
{
	t_scene_id	i;

	i = 0;
	if (paths)
	{
		while (i < TEX_COUNT)
		{
			if (i == 0)
				printf("NO: %s\n", paths[i]);
			else if (i == 1)
				printf("SO: %s\n", paths[i]);
			else if (i == 2)
				printf("WE: %s\n", paths[i]);
			else if (i == 3)
				printf("EA: %s\n", paths[i]);
			++i;
		}
	}
}
