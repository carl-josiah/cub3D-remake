/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:20:13 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/01 11:06:15 by ccastro          ###   ########.fr       */
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

void	error_system(t_game *game, char *context);
void	error_arguments(char *msg);
void	error_parse(t_game *game, char *msg);

#endif
