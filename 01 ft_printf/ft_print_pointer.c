/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 08:28:09 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 13:19:15 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long long nb)
{
	int	n;

	n = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 16;
		n++;
	}
	return (n);
}

static void	ft_write_pointer(unsigned long long nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
		ft_write_pointer(nb / 16);
	write(1, &base[nb % 16], 1);
}

int	ft_print_pointer(unsigned long long pointer)
{
	if (pointer == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		ft_write_pointer(pointer);
	}
	return (ft_ptrlen(pointer) + 2);
}
