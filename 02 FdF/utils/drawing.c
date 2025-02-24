/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:45:58 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/24 17:00:49 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fdf.h"

static void	slope_less_than_one(mlx_image_t *img, int dx, int dy, t_point *a)
{
	t_drawing	d;

	d.color = 0xFFFFFFFF;
	d.p = 2 * abs(dy) - abs(dx);
	d.x = a->iso_x;
	d.y = a->iso_y;
	d.i = -1;
	while (++d.i < abs(dx))
	{
		if (dx > 0)
			d.x++;
		else
			d.x--;
		if (d.p < 0)
			d.p = d.p + 2 * abs(dy);
		else
		{
			if (dy > 0)
				d.y++;
			else
				d.y--;
			d.p = d.p + 2 * abs(dy) - 2 * abs(dx);
		}
		mlx_put_pixel(img, d.x, d.y, d.color);
	}
}

static void	slope_more_than_one(mlx_image_t *img, int dx, int dy, t_point *a)
{
	t_drawing	d;

	d.color = 0xFFFFFFFF;
	d.p = 2 * abs(dx) - abs(dy);
	d.x = a->iso_x;
	d.y = a->iso_y;
	d.i = -1;
	while (++d.i < abs(dy))
	{
		if (dy > 0)
			d.y++;
		else
			d.y--;
		if (d.p < 0)
			d.p = d.p + 2 * abs(dx);
		else
		{
			if (dx > 0)
				d.x++;
			else
				d.x--;
			d.p = d.p + 2 * abs(dx) - 2 * abs(dy);
		}
		mlx_put_pixel(img, d.x, d.y, d.color);
	}
}

static void	draw_line(mlx_image_t *img, t_point *a, t_point *b)
{
	int	dx;
	int	dy;

	dx = b->iso_x - a->iso_x;
	dy = b->iso_y - a->iso_y;
	if (abs(dx) > abs(dy))
		slope_less_than_one(img, dx, dy, a);
	else
		slope_more_than_one(img, dx, dy, a);
}

void	create_image(mlx_image_t *img, t_map *map, float angle)
{
	int	i;
	int	j;

	i = -1;
	map->angle = angle;
	convert_to_2d(map);
	while (++i < map->depth - 1)
	{
		j = -1;
		while (++j < map->width - 1)
		{
			draw_line(img, &map->points[i][j], &map->points[i][j + 1]);
			draw_line(img, &map->points[i][j], &map->points[i + 1][j]);
		}
		draw_line(img, &map->points[i][j], &map->points[i + 1][j]);
	}
	j = -1;
	while (++j < map->width - 1)
		draw_line(img, &map->points[i][j], &map->points[i][j + 1]);
}
