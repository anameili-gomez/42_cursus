/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:20:29 by anagomez          #+#    #+#             */
/*   Updated: 2024/12/04 19:20:30 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

char	*find_path(char *command, char **env)
{
	char	**directories;
	char	*directory;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	directories = ft_split(&env[i][5], ':');
	i = -1;
	while (directories[++i])
	{
		directory = ft_strjoin(directories[i], "/");
		path = ft_strjoin(directory, command);
		if (path && access(path, F_OK) == 0)
		{
			free(directory);
			free_split(directories);
			return (path);
		}
		free(directory);
		free(path);
	}
	free_split(directories);
	return (NULL);
}

void	ft_execute(char *cmd, char **env)
{
	char	**command;
	char	*path;

	command = ft_split(cmd, ' ');
	if (!command)
	{
		write(2, "Split fail\n", 11);
		exit(0);
	}
	path = find_path(command[0], env);
	if (!path)
	{
		free_split(command);
		write(2, "No path found\n", 14);
		exit(0);
	}
	execve(path, command, env);
	free_split(command);
	free(path);
	exit(0);
}

int	open_file(char *file, int in_or_out)
{
	int	file_int;

	if (in_or_out == 0)
		file_int = open(file, O_RDONLY);
	if (in_or_out == 1)
		file_int = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_int == -1)
	{
		write(2, "File not reachable\n", 19);
		exit(0);
	}
	return (file_int);
}
