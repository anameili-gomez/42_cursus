/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:38:21 by anagomez          #+#    #+#             */
/*   Updated: 2025/01/13 12:38:23 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fdf.h"

static void	scaling1(t_map *map, int mw, int mh)
{
	int		i;
	int		j;
	float	zoom;

	zoom = 0;
	if ((float)WIDTH / (float)mw < (float)HEIGHT / (float)mh)
		zoom = (float)WIDTH / (float)mw;
	else
		zoom = (float)HEIGHT / (float)mh;
	i = -1;
	while (++i < map->depth)
	{
		j = -1;
		while (++j < map->width)
		{
			map->points[i][j].x *= zoom;
			map->points[i][j].y *= zoom;
			map->points[i][j].z *= zoom;
		}
	}
}

static void	scaling2(t_map *map, int mw, int mh)
{
	int		i;
	int		j;
	float	zoom;

	if ((map->x_max - map->x_min) / mw < (map->y_max - map->y_min) / mh)
		zoom = (float)WIDTH / (float)mw;
	else
		zoom = (float)HEIGHT / (float)mh;
	i = -1;
	while (++i < map->depth)
	{
		j = -1;
		while (++j < map->width)
		{
			map->points[i][j].iso_x *= zoom;
			map->points[i][j].iso_y *= zoom;
		}
	}
}

static void	do_isometric(t_point *vector, float angle)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	vector->iso_x = (vector->y - vector->x) * cos_angle;
	vector->iso_y = (vector->x + vector->y) * sin_angle - vector->z;
}

static void	centering(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->depth)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].iso_x -= (map->x_max + map->x_min) / 2.0;
			map->points[i][j].iso_y -= (map->y_max + map->y_min) / 2.0;
			map->points[i][j].iso_x += WIDTH / 2.0;
			map->points[i][j].iso_y += HEIGHT / 2.0;
			j++;
		}
		i++;
	}
}

void	convert_to_2d(t_map *map)
{
	int	i;
	int	j;

	scaling1(map, map->width, map->depth);
	i = -1;
	while (++i < map->depth)
	{
		j = -1;
		while (++j < map->width)
			do_isometric(&map->points[i][j], map->angle);
	}
	find_max_and_min(map);
	scaling2(map, map->x_max - map->x_min, map->y_max - map->y_min);
	find_max_and_min(map);
	centering(map);
}
