/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:48:52 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/24 16:24:33 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	heredoc_input(char *limiter)
{
	char	*input;
	size_t	len;
	int		pipe_in[2];

	len = ft_strlen(limiter);
	if (pipe(pipe_in) == -1)
		exit_message(2, NULL);
	while (1)
	{
		ft_printf("here_doc > ");
		input = get_next_line(0);
		input[ft_strlen(input) - 1] = '\0';
		if (ft_strlen(input) == len && ft_strncmp(input, limiter, len) == 0)
		{
			free(input);
			break ;
		}
		ft_putstr_fd(input, pipe_in[1]);
		ft_putstr_fd("\n", pipe_in[1]);
		free(input);
	}
	close(pipe_in[1]);
	return (pipe_in[0]);
}

void	closing(int *readfd, int ac, char **av, char **env)
{
	int		fd;
	pid_t	pid;

	if (ft_strncmp(av[1], "here_doc", 8) == 0 && ft_strlen(av[1]) == 8)
		fd = open_file(av[ac - 1], 2);
	else
		fd = open_file(av[ac - 1], 1);
	close(readfd[1]);
	pid = fork();
	if (pid == -1)
		exit_message(2, readfd);
	else if (pid == 0)
		child_process(readfd[0], fd, av[ac - 2], env);
	close(readfd[0]);
	close(fd);
}

void	child_process(int readfd, int writefd, char *cmd, char **env)
{
	dup2(readfd, 0);
	close(readfd);
	dup2(writefd, 1);
	close(writefd);
	ft_execute(cmd, env);
}

int	starter(int ac, char **av)
{
	int	fd;

	if (ft_strncmp(av[1], "here_doc", 8) == 0 && ft_strlen(av[1]) == 8)
	{
		if (ac < 6)
		{
			write(2, "Arguments don't match the format\n", 33);
			exit(1);
		}
		return (heredoc_input(av[2]));
	}
	else
	{
		fd = open_file(av[1], 0);
		return (fd);
	}
}
