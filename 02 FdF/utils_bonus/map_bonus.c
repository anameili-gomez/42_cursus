/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:45:04 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 15:46:42 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fdf_bonus.h"

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
	t_file	*node;

	node = (t_file *)malloc(sizeof(t_file));
	node->next = NULL;
	node->points = NULL;
	return (node);
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

t_map	get_map(char *file)
{
	int		fd;
	t_map	map;
	t_file	*lst;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_exit("Map not reachable", NULL, NULL, 1);
	lst = read_file(fd);
	close(fd);
	map.depth = get_depth(lst);
	map.width = get_width(lst->points);
	map.alpha = 0.785398;
	map.beta = 0.61548;
	map.points = get_points(map.depth, map.width, lst);
	scaling_and_centering(&map);
	return (map);
}
