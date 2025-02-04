/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:26:31 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 13:21:20 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_line_length(char *stash)
{
	size_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	return (i);
}

int	ft_line_control(char *stash)
{
	while (*stash != '\0')
	{
		if (*stash == '\n')
			return (1);
		stash++;
	}
	return (0);
}

char	*ft_get_new_stash(void)
{
	char	*stash;

	stash = (char *)malloc(sizeof(char) * 1);
	if (!stash)
		return (NULL);
	stash[0] = '\0';
	return (stash);
}
