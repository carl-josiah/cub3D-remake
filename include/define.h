/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:42:31 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/01 20:33:35 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// error_system.c
# define ERROR_MALLOC "malloc() failed"
# define ERROR_CALLOC "ft_calloc() failed"
# define ERROR_OPEN "open() failed"

// error_arguments.c
# define ERROR_COUNT "Invalid argument count (must be 2)"
# define ERROR_FILE "Invalid file extension (must be a .cub file)"
# define ERROR_FILENAME "Invalid filename (must be [filename].cub)"
# define ERROR_SPACE "Invalid argument (must not contain spaces)"

// error_parse.c
# define ERROR_CONFIG "Invalid Configuration"

#endif
