/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:33:50 by anagomez          #+#    #+#             */
/*   Updated: 2025/01/24 10:33:51 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fdf_bonus.h"

static void	redo_isometric(t_point *point, t_map *map)
{
	float	trig[4];
	float	temp_x;
	float	temp_y;

	trig[0] = cos(map->alpha);
	trig[1] = sin(map->alpha);
	trig[2] = cos(map->beta);
	trig[3] = sin(map->beta);
	temp_x = point->x - map->center_x;
	temp_y = point->y - map->center_y;
	point->iso_x = trig[0] * temp_x;
	point->iso_x -= trig[1] * temp_y;
	point->iso_x += map->center_x;
	point->iso_y = trig[1] * trig[2] * temp_x;
	point->iso_y += trig[0] * trig[2] * temp_y;
	point->iso_y -= trig[3] * point->z;
	point->iso_y += map->center_y;
}

static void	redo_scaling(t_map *map)
{
	int		i;
	int		j;
	float	temp_x;
	float	temp_y;

	i = -1;
	while (++i < map->depth)
	{
		j = -1;
		while (++j < map->width)
		{
			temp_x = map->points[i][j].iso_x - map->center_x;
			temp_y = map->points[i][j].iso_y - map->center_y;
			map->points[i][j].iso_x = temp_x * map->zoom + map->center_x;
			map->points[i][j].iso_y = temp_y * map->zoom + map->center_y;
		}
	}
}

static void	redo_centering(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->depth)
	{
		j = -1;
		while (++j < map->width)
		{
			map->points[i][j].iso_x += map->x_offset;
			map->points[i][j].iso_y += map->y_offset;
		}
	}
}

void	redo_iso(t_map *map, int time)
{
	int		i;
	int		j;
	int		og_x;
	int		og_y;

	i = -1;
	if (time == 0)
	{
		og_x = map->points[0][0].iso_x;
		og_y = map->points[0][0].iso_y;
	}
	while (++i < map->depth)
	{
		j = -1;
		while (++j < map->width)
			redo_isometric(&map->points[i][j], map);
	}
	redo_scaling(map);
	if (time == 0)
	{
		map->x_offset = og_x - map->points[0][0].iso_x;
		map->y_offset = og_y - map->points[0][0].iso_y;
	}
	redo_centering(map);
}
