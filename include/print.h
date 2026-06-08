/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:15:20 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/07 14:49:58 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include "enum.h"
# include <stdio.h>

void	print_lines(const char **lines);
void	print_bits(const int num);
void	print_state(const char *line, const t_state state);
void	print_paths(const char *paths[]);

#endif
