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

// typedef struct s_vec2i	t_vec2i;
// typedef struct s_vec2d	t_vec2d;
// typedef struct s_grid	t_grid;
// typedef struct s_player	t_player;
// typedef struct s_map	t_map;
// typedef struct s_col	t_col;
// typedef struct s_tex	t_tex;
// typedef struct s_file	t_file;
// typedef struct s_config	t_config;
// typedef struct s_game	t_game;

typedef struct s_vec2i
{
	int			x;
	int			y;
}				t_vec2i;

typedef struct s_vec2d
{
	double		x;
	double		y;
}				t_vec2d;

typedef struct s_grid
{
	char		**matrix;
	t_vec2i		size;
	char		(*get_tile)(struct s_grid *self, t_vec2i pos);
	int			(*is_wall)(struct s_grid *self, t_vec2i pos);
}				t_grid;

typedef struct s_player
{
	t_vec2d		pos;
	t_vec2d		dir;
	t_vec2d		plane;
	char		spawn_dir;
	void		(*rotate)(struct s_player *self, double rot_speed);
	void		(*move)(struct s_player *self, t_grid *grid, double move_speed);
}				t_player;

typedef struct s_map
{
	t_grid		grid;
	t_player	player;
}				t_map;

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
	int			(*init)(struct s_game *self, int argc, char argv);
	void		(*destructor)(struct s_game *self);
	t_config	conf;
	t_map		map;
}				t_game;

#endif
