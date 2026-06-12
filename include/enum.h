/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 02:31:43 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/11 14:30:09 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_path
{
	PATH_NORTH = 0,
	PATH_SOUTH = 1,
	PATH_WEST = 2,
	PATH_EAST = 3
}	t_path;

typedef enum e_rgb
{
	RGB_FLOOR = 0,
	RGB_CEILING = 1
}	t_rgb;

typedef enum e_state
{
	STATE_CONFIG,
	STATE_MAP,
}	t_state;

typedef enum e_scene_id
{
	TEX_NORTH = 1 << 0,
	TEX_SOUTH = 1 << 1,
	TEX_WEST = 1 << 2,
	TEX_EAST = 1 << 3,
	COL_FLOOR = 1 << 4,
	COL_CEILING = 1 << 5,
	TEX_COUNT = 4,
	COL_COUNT = 2,
	ID_COUNT = TEX_COUNT + COL_COUNT,
	TEX_ALL = (TEX_NORTH | TEX_SOUTH | TEX_WEST | TEX_EAST),
	COL_ALL = (COL_FLOOR | COL_CEILING),
	ID_ALL = (TEX_ALL | COL_ALL)
}	t_scene_id;

#endif
