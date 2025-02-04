/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:50:25 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 12:57:00 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*newdest;
	unsigned char	*newsrc;

	i = 0;
	newdest = (unsigned char *)dest;
	newsrc = (unsigned char *)src;
	while (i < n)
	{
		newdest[i] = newsrc[i];
		i++;
	}
	return (dest);
}
