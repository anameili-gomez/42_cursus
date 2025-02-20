/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:33:06 by anagomez          #+#    #+#             */
/*   Updated: 2024/11/28 16:33:07 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	int		i;
	int		pipefd[2];
	int		pipe_in;
	pid_t	pid;

	if (ac < 5 || pipe(pipefd) == -1)
		exit_message(2 - (ac < 5), NULL);
	pipe_in = starter(ac, av);
	i = 1 + (ft_strncmp(av[1], "here_doc", 8) == 0 && ft_strlen(av[1]) == 8);
	while (++i <= ac - 3)
	{
		if (pipe(pipefd) == -1)
			exit_message(2, NULL);
		pid = fork();
		if (pid == -1)
			exit_message(2, pipefd);
		else if (pid == 0)
			child_process(pipe_in, pipefd[1], av[i], env);
		close(pipefd[1]);
		close(pipe_in);
		pipe_in = pipefd[0];
		wait(&pid);
	}
	closing(pipefd, ac, av, env);
	return (0);
}
