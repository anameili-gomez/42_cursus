/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:26:06 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 13:20:41 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_resetstash(char *stash, size_t n)
{
	char	*new_stash;
	size_t	i;

	i = 0;
	if (!stash || stash[n] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = (char *)malloc(sizeof(char) * (gnl_strlen(stash) - n + 1));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	n++;
	while (stash[n])
		new_stash[i++] = stash[n++];
	new_stash[i] = '\0';
	free (stash);
	return (new_stash);
}

char	*stash_to_line(char *stash)
{
	char	*line;
	size_t	length;
	size_t	i;

	if (stash[0] == '\0')
		return (NULL);
	length = ft_line_length(stash);
	line = (char *)malloc(sizeof(char) * length + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*rl_to_stash(char *read_line, char *stash)
{
	char	*new_stash;
	size_t	space;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!read_line || !stash)
		return (NULL);
	space = gnl_strlen(read_line) + gnl_strlen(stash) + 1;
	new_stash = (char *)malloc((sizeof (char)) * space);
	if (!new_stash)
		return (NULL);
	while (stash[i])
	{
		new_stash[i] = stash[i];
		i++;
	}
	while (read_line[j])
		new_stash[i++] = read_line[j++];
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

char	*read_to_stash(int fd, char *stash)
{
	char	*read_line;
	ssize_t	read_bytes;

	if (!stash)
		stash = ft_get_new_stash();
	read_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_line || !stash)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, read_line, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(stash);
			free(read_line);
			return (NULL);
		}
		read_line[read_bytes] = '\0';
		stash = rl_to_stash(read_line, stash);
		if (!stash || ft_line_control(read_line) == 1)
			break ;
	}
	free(read_line);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
	{
		free(stash[fd]);
		return (NULL);
	}
	stash[fd] = read_to_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = stash_to_line(stash[fd]);
	stash[fd] = ft_resetstash(stash[fd], ft_line_length(stash[fd]));
	return (line);
}
