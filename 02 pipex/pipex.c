/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:20:20 by anagomez          #+#    #+#             */
/*   Updated: 2024/12/04 19:20:21 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(char **av, char **env, int *pipefd)
{
	int	fd;

	fd = open_file(av[1], 0);
	close(pipefd[0]);
	dup2(fd, 0);
	close(fd);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	ft_execute(av[2], env);
}

static void	parent_process(char **av, char **env, int *pipefd)
{
	int	fd;

	fd = open_file(av[4], 1);
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	dup2(fd, 1);
	close(fd);
	ft_execute(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (ac != 5)
		return (write(2, "Arguments don't match the format\n", 33));
	if (pipe(pipefd) == -1)
		return (write(2, "Pipe fail\n", 10));
	pid = fork();
	if (pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		write(2, "Fork fail\n", 10);
		return (1);
	}
	else if (pid == 0)
		child_process(av, env, pipefd);
	else
	{
		wait(&pid);
		parent_process(av, env, pipefd);
	}
}
