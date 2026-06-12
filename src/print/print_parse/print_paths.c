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

#include "../../../include/print.h"

void	print_paths(t_tex *tex)
{
	if (!tex)
		return ;
	if (tex->paths[PATH_NORTH])
		printf("NO: %s\n", tex->paths[PATH_NORTH]);
	if (tex->paths[PATH_SOUTH])
		printf("SO: %s\n", tex->paths[PATH_SOUTH]);
	if (tex->paths[PATH_WEST])
		printf("WE: %s\n", tex->paths[PATH_WEST]);
	if (tex->paths[PATH_EAST])
		printf("EA: %s\n", tex->paths[PATH_EAST]);
}
