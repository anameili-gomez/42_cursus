/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:08:55 by anagomez          #+#    #+#             */
/*   Updated: 2024/12/23 17:26:31 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fdf.h"

int	get_width(char **points)
{
	int	i;

	i = 0;
	while (points[i] && points[i][0] != '\n')
		i++;
	return (i);
}

static int	get_depth(t_file *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

static t_file	*get_new_node(void)
{
	t_file	*new_node;

	new_node = (t_file *)malloc(sizeof(t_file) * 1);
	new_node->next = NULL;
	new_node->points = NULL;
	return (new_node);
}

static t_file	*read_file(int fd)
{
	char	*line;
	t_file	*head;
	t_file	*new_node;
	t_file	*last_node;

	head = NULL;
	line = get_next_line(fd);
	while (line)
	{
		new_node = get_new_node();
		new_node->points = ft_split(line, ' ');
		if (!head)
		{
			head = new_node;
			last_node = new_node;
		}
		else
		{
			last_node->next = new_node;
			last_node = last_node->next;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (head);
}

t_map	get_map(char *input)
{
	int		fd;
	t_map	map;
	t_file	*lst;

	fd = open(input, O_RDONLY);
	if (fd == -1)
		ft_exit("Map not reachable", NULL, NULL, 1);
	lst = read_file(fd);
	close(fd);
	map.depth = get_depth(lst);
	map.width = get_width(lst->points);
	map.points = get_points(map.depth, map.width, lst);
	return (map);
}
