/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:24:31 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/24 16:21:35 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new_stash;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (s1);
	i = 0;
	j = 0;
	new_stash = (char *)malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!new_stash)
		return (NULL);
	while (s1[i])
		new_stash[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_stash[j++] = s2[i++];
	new_stash[j] = '\0';
	free(s1);
	return (new_stash);
}

int	line_found(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
