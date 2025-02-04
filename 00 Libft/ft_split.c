/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:12:10 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 12:57:39 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substrings(char const *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			n++;
		i++;
	}
	return (n);
}

static int	*ft_wordlen(char const *s, char c)
{
	int	count;
	int	*wordlen;
	int	i;

	i = 0;
	count = ft_substrings(s, c);
	wordlen = malloc(sizeof(int) * count);
	if (wordlen == NULL)
		return (NULL);
	while (i < count)
	{
		wordlen[i] = 0;
		while (*s == c)
			s++;
		while (*s != c && *s != '\0')
		{
			wordlen[i]++;
			s++;
		}
		i++;
	}
	return (wordlen);
}

static void	ft_freespace(char **array, int i)
{
	while (i >= 0)
	{
		if (array[i] != NULL)
			free(array[i]);
		i--;
	}
	free(array);
	return ;
}

static char	*ft_copy(char const *s, char c, int n, int size)
{
	int		i;
	int		j;
	char	*array;

	if (size < 0)
		return (NULL);
	i = 0;
	j = 0;
	array = malloc(sizeof(char) * (size + 1));
	if (array == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			n--;
		if (n == 0)
		{
			while (s[i] != c && s[i] != '\0')
				array[j++] = s[i++];
			break ;
		}
		i++;
	}
	array[j] = '\0';
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		*wordlen;
	size_t	j;
	char	**array;

	i = 0;
	j = ft_substrings(s, c);
	wordlen = ft_wordlen(s, c);
	array = malloc(sizeof(char *) * (j + 1));
	if (array == NULL || s == NULL || wordlen == NULL)
		return (NULL);
	while (i < j)
	{
		array[i] = ft_copy(s, c, i + 1, wordlen[i]);
		if (array[i] == NULL)
		{
			ft_freespace(array, i - 1);
			return (NULL);
		}
		i++;
	}
	array[j] = NULL;
	free(wordlen);
	return (array);
}
