/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:27:40 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:40:08 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_resetstash(char *stash, size_t n);
char	*stash_to_line(char *stash);
char	*rl_to_stash(char *read_line, char *stash);
char	*read_to_stash(int fd, char *stash);
char	*get_next_line(int fd);

size_t	gnl_strlen(const char *s);
size_t	ft_line_length(char *stash);
int		ft_line_control(char *stash);
char	*ft_get_new_stash(void);

#endif
