/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:43:15 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 15:46:46 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fdf_bonus.h"

static int	get_z(char *point)
{
	int	z;
	int	s;
	int	i;

	z = 0;
	s = 1;
	i = 0;
	if (point[i] == '-')
	{
		s = -1;
		i++;
	}
	while (point[i] >= '0' && point[i] <= '9')
	{
		z *= 10;
		z += point[i] - '0';
		i++;
	}
	return (z * s);
}

static t_point	*populate_point_line(char **points, int width, int i)
{
	t_point	*line;
	int		j;

	j = 0;
	line = (t_point *)malloc(sizeof(t_point) * width);
	while (j < width)
	{
		line[j].x = j;
		line[j].y = i;
		line[j].z = get_z(points[j]);
		get_colors(&line[j], ft_strchr(points[j], ','));
		j++;
	}
	return (line);
}

t_point	**get_points(int depth, int width, t_file *lst)
{
	t_point	**points;
	t_file	*to_free;
	int		i;

	i = 0;
	points = (t_point **)malloc(sizeof(t_point *) * depth);
	while (i < depth)
	{
		if (get_width(lst->points) != width)
		{
			free_lst(lst);
			free_points(points, i);
			ft_exit("Map must be rectangle", NULL, NULL, 1);
		}
		points[i] = populate_point_line(lst->points, width, i);
		free_split(lst->points);
		to_free = lst;
		lst = lst->next;
		free(to_free);
		i++;
	}
	return (points);
}

static void	find_center(t_map *map)
{
	int		i;
	int		j;
	float	total_points;

	map->center_x = 0;
	map->center_y = 0;
	total_points = 0;
	i = -1;
	while (++i < map->depth)
	{
		j = -1;
		while (++j < map->width)
		{
			map->center_x += (float)map->points[i][j].x;
			map->center_y += (float)map->points[i][j].y;
			total_points++;
		}
	}
	map->center_x /= total_points;
	map->center_y /= total_points;
}

void	find_max_and_min(t_map *map)
{
	int	i;
	int	j;

	map->x_max = map->points[0][0].iso_x;
	map->x_min = map->points[0][0].iso_x;
	map->y_max = map->points[0][0].iso_y;
	map->y_min = map->points[0][0].iso_y;
	i = -1;
	while (++i < map->depth)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->points[i][j].iso_x > map->x_max)
				map->x_max = map->points[i][j].iso_x;
			if (map->points[i][j].iso_x < map->x_min)
				map->x_min = map->points[i][j].iso_x;
			if (map->points[i][j].iso_y > map->y_max)
				map->y_max = map->points[i][j].iso_y;
			if (map->points[i][j].iso_y < map->y_min)
				map->y_min = map->points[i][j].iso_y;
		}
	}
	find_center(map);
}
