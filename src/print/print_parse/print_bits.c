/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 18:42:24 by ccastro           #+#    #+#             */
/*   Updated: 2026/06/07 14:49:02 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/print.h"

void	print_bits(int num)
{
	int	total_bits;
	int	i;
	int	bit;

	total_bits = sizeof(num) * 8;
	i = total_bits - 1;
	bit = 0;
	while (i >= 0)
	{
		bit = (num >> i) & 1;
		printf("%d", bit);
		--i;
	}
	printf("\n");
}
