/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 08:28:44 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 13:19:12 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_order(int n)
{
	int	order;

	order = 1;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		order++;
	}
	return (order);
}

static int	ft_exp(int n)
{
	int	res;

	res = 1;
	while (n > 1)
	{
		res = res * 10;
		n--;
	}
	return (res);
}

int	ft_print_integer(int nb)
{
	int		count;
	int		order;
	char	digit;

	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11), 11);
	order = ft_order(nb);
	if ((nb < 0))
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	while (order > 0)
	{
		digit = (nb / ft_exp(order)) + '0';
		write(1, &digit, 1);
		nb = nb % ft_exp(order);
		order--;
		count++;
	}
	return (count);
}
