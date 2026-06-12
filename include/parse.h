/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:41:06 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/10 19:01:38 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../lib/incs/libft.h"
# include "define.h"
# include "error.h"
# include "print.h"
# include "struct.h"
# include <stdio.h>
# include <unistd.h>

void	read_scene(t_game *game, const char *file_path);
void	parse_scene(t_game *game, const char *file_path);
void	parse_config(t_game *game, char *line, t_config *conf);
void	parse_map(t_game *game, char *line, t_map *map);
void	count_and_skip(t_game *game, char **line, t_scene_id id);
int		open_fd(const char *file_path, int *fd);
int		count_commas(const char *line);
void	parse_color(t_game *game, char *line, t_scene_id id);
void	parse_texture(t_game *game, char *line, t_scene_id id);
int		is_valid_color_value(char *line);
void	identify_color_channel(size_t num_count, int channel, t_col *color, int which_rgb);

#endif
