/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:20:13 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/04 19:27:30 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "../lib/incs/libft.h"
# include "define.h"
# include "struct.h"
# include "free.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

void	error_system(t_game *game, const char *context, const char *line);
void	error_arguments(const char *msg);
void	error_parse(t_game *game, const char *msg, const char *line);

#endif
