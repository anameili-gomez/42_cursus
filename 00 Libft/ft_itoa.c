/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:18:28 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 12:55:53 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_order(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_zero(void)
{
	char	*zero;

	zero = (char *)malloc(2);
	if (zero == NULL)
		return (NULL);
	zero[0] = '0';
	zero[1] = '\0';
	return (zero);
}

char	*ft_itoa(int n)
{
	size_t			i;
	unsigned int	nbr;
	char			*num;

	if (n == 0)
		return (ft_zero());
	i = ft_order(n);
	nbr = n;
	num = (char *)malloc(i + 1);
	if (num == 0)
		return (NULL);
	if (n < 0)
	{
		num[0] = '-';
		nbr = -n;
	}
	num[i] = '\0';
	while (nbr > 0)
	{
		num[--i] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (num);
}
