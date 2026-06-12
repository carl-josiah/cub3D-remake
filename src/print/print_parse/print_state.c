/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:02:08 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/11 14:35:33 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/print.h"

void	print_state(char *line, t_state state)
{
	if (!line || (state < 0 || state > 1))
		return ;
	if (state == STATE_CONFIG && line)
		printf("STATE_CONFIG: %s", line);
	else if (state == STATE_MAP && line)
		printf("STATE_MAP: %s", line);
	else if (state == STATE_CONFIG)
		printf("STATE_CONFIG\n");
	else if (state == STATE_MAP)
		printf("STATE_MAP\n");
}
