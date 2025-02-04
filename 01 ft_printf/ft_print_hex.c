/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:53:43 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 13:19:08 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nb, int uplow)
{
	char	*base;
	int		count;

	count = 0;
	base = 0;
	if (uplow == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
		count = count + ft_print_hex(nb / 16, uplow);
	write (1, &base[nb % 16], 1);
	count++;
	return (count);
}
