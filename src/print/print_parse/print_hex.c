/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:49:22 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/10 19:07:53 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/print.h"

void	print_hex(t_col *color)
{
	if (color->rgb[RGB_FLOOR])
	{
		printf("floor_color: ");
		printf("0x%06X\n", color->rgb[RGB_FLOOR]);
	}
	if (color->rgb[RGB_CEILING])
	{
		printf("ceiling_color: ");
		printf("0x%06X\n", color->rgb[RGB_CEILING]);
	}
}
