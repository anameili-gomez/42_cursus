/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:52:01 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 15:46:38 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fdf_bonus.h"

static void	scaling1(t_map *map, int mw, int mh)
{
	int		i;
	int		j;
	float	zoom;

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

static void	do_isometric(t_point *point, float alpha, float beta)
{
	float	cos_alpha;
	float	sin_alpha;
	float	cos_beta;
	float	sin_beta;

	cos_alpha = cos(alpha);
	sin_alpha = sin(alpha);
	cos_beta = cos(beta);
	sin_beta = sin(beta);
	point->iso_x = cos_alpha * point->x;
	point->iso_x -= sin_alpha * point->y;
	point->iso_y = sin_alpha * cos_beta * point->x;
	point->iso_y += cos_alpha * cos_beta * point->y;
	point->iso_y -= sin_beta * point->z;
}

static void	scaling2(t_map *map, int mw, int mh)
{
	int		i;
	int		j;

	if ((map->x_max - map->x_min) / mw < (map->y_max - map->y_min) / mh)
		map->zoom = (float)WIDTH / (float)mw;
	else
		map->zoom = (float)HEIGHT / (float)mh;
	i = -1;
	while (++i < map->depth)
	{
		j = -1;
		while (++j < map->width)
		{
			map->points[i][j].iso_x *= map->zoom;
			map->points[i][j].iso_y *= map->zoom;
		}
	}
}

static void	centering(t_map *map)
{
	int	i;
	int	j;

	map->x_offset = (WIDTH / 2.0) - ((map->x_max + map->x_min) / 2.0);
	map->y_offset = (HEIGHT / 2.0) - ((map->y_max + map->y_min) / 2.0);
	i = 0;
	while (i < map->depth)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].iso_x += map->x_offset;
			map->points[i][j].iso_y += map->y_offset;
			j++;
		}
		i++;
	}
	find_max_and_min(map);
	redo_iso(map, 0);
}

void	scaling_and_centering(t_map *map)
{
	int	i;
	int	j;

	scaling1(map, map->width, map->depth);
	i = -1;
	while (++i < map->depth)
	{
		j = -1;
		while (++j < map->width)
			do_isometric(&map->points[i][j], map->alpha, map->beta);
	}
	find_max_and_min(map);
	scaling2(map, map->x_max - map->x_min, map->y_max - map->y_min);
	find_max_and_min(map);
	centering(map);
}
