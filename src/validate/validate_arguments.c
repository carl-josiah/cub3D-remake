/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:13:08 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/02 20:13:50 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/validate.h"

void	validate_arguments(int ac, char **av)
{
	const char	*ext;
	const char	*ptr;

	if (ac != 2)
		error_arguments(ERROR_COUNT);
	ptr = av[1];
	while (*ptr)
	{
		if (ft_isspace(*ptr))
			error_arguments(ERROR_SPACE);
		++ptr;
	}
	ext = ft_strrchr(av[1], '.');
	if (!ext || ft_strcmp(".cub", ext) != 0)
		error_arguments(ERROR_FILE);
	if (ext == av[1] || *(ext - 1) == '/' || *(ext - 1) == '.')
		error_arguments(ERROR_FILENAME);
}
