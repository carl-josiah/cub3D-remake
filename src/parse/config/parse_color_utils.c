/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:56:06 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/10 19:01:14 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse.h"

int	is_valid_color_value(char *line)
{
	int		num;
	size_t	num_count;
	size_t	i;

	num_count = 0;
	i = 0;
	while (num_count < CHANNEL_COUNT)
	{
		num = ft_atoi(&line[i]);
		if (num > 255 || num < 0)
			return (0);
		while (line[i] && ft_isdigit(line[i]))
			++i;
		if (line[i] == ',')
			++i;
		++num_count;
	}
	return (1);
}

void	identify_color_channel(size_t num_count, int channel, t_col *color, int which_rgb)
{
	if (num_count == 0)
		color->rgb[which_rgb] |= channel << 16;
	else if (num_count == 1)
		color->rgb[which_rgb] |= channel << 8;
	else if (num_count == 2)
		color->rgb[which_rgb] |= channel;
}
