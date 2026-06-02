/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:41:06 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/02 20:53:13 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../lib/incs/libft.h"
# include "error.h"
# include "define.h"
# include "struct.h"
# include "print.h"
# include <stdio.h>
# include <unistd.h>

void	read_scene(t_game *game, const char *file_path);
void	parse_scene(t_game *game, const char *file_path);

#endif
