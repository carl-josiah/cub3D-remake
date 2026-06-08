/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 10:06:44 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/06 22:55:05 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "../lib/incs/libft.h"
# include "enum.h"

typedef struct s_map
{	
	
}	t_map;

typedef struct s_col
{
	int			rgb[COL_COUNT];
}				t_col;

typedef struct s_tex
{
	char		*paths[TEX_COUNT];
}				t_tex;

typedef struct s_file
{
	char		**lines;
	size_t		line_count;
}				t_file;

typedef struct s_config
{
	t_tex		tex;
	t_col		col;
	t_file		file;
	int			bits;
}				t_config;

typedef struct s_game
{
	t_config	conf;
	t_map		map;
}				t_game;

#endif
