/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:30:00 by anagomez          #+#    #+#             */
/*   Updated: 2024/11/28 17:30:06 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../pipex.h"

int		heredoc_input(char *limiter);
void	closing(int *readfd, int ac, char **av, char **env);
void	child_process(int readfd, int writefd, char *cmd, char **env);
int		starter(int ac, char **av);

void	free_split(char **array);
char	*find_path(char *command, char **env);
void	ft_execute(char *cmd, char **env);
int		open_file(char *file, int in_or_out);
int		exit_message(int n, int *pipefd);

#endif
