/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:15:20 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/11 14:20:33 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include "enum.h"
# include "struct.h"
# include <stdio.h>

void	print_lines(char **lines);
void	print_bits(int num);
void	print_state(char *line, t_state state);
void	print_paths(t_tex *tex);
void	print_hex(t_col *color);

/**
 * @brief Prints the individual channel lines of
 * floor and ceiling. Recommended to be called in
 * inside parse_colors() for ease of use.
 *
 * @param channel_line is the line to be printed
 * @param id is to figure out whether it belongs to
 * floor or ceiling
 *
 */
void	print_channels(char *channel_line, t_scene_id id);

#endif
