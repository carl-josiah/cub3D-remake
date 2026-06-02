/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 02:31:43 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/02 21:52:39 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_tex_id
{
	TEX_NORTH,
	TEX_SOUTH,
	TEX_WEST,
	TEX_EAST,
	TEX_COUNT
}	t_tex_id;

typedef enum e_col_id
{
	COL_FLOOR,
	COL_CEILING,
	COL_COUNT
}	t_col_id;

typedef enum e_scene_element
{
	ELEM_NORTH = 1 << 0,
	ELEM_SOUTH = 1 << 1,
	ELEM_WEST = 1 << 2,
	ELEM_EAST = 1 << 3,
	ELEM_FLOOR = 1 << 4,
	ELEM_CEILING = 1 << 5,
	ELEM_ALL_CONFIG = (ELEM_NORTH | ELEM_SOUTH |
	ELEM_WEST | ELEM_EAST | ELEM_FLOOR | ELEM_CEILING)
}	t_scene_element;

#endif
