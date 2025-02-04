/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:32:44 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 12:57:20 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	char			digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	nbr = (unsigned int)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = (unsigned int)(-n);
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	digit = (nbr % 10) + '0';
	write(fd, &digit, 1);
	return ;
}
