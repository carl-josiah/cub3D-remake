/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_channels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:53:05 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/11 14:20:25 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/print.h"

void	print_channels(char *channel_line, t_scene_id id)
{
	if ((id & COL_FLOOR) == COL_FLOOR)
		printf("Floor channels: %s", channel_line);
	if ((id & COL_CEILING) == COL_CEILING)
		printf("Ceiling channels: %s", channel_line);
}
