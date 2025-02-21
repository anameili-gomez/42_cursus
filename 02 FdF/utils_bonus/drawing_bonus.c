/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:29:55 by anagomez          #+#    #+#             */
/*   Updated: 2025/01/17 17:29:56 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fdf_bonus.h"

static void	get_steps(t_drawing *line, t_point *a, t_point *b)
{
	int	div;

	if (abs(line->dx) > abs(line->dy))
		div = abs(line->dx);
	else
		div = abs(line->dy);
	if (div != 0)
	{
		line->r = (b->r - a->r) / div;
		line->g = (b->g - a->g) / div;
		line->b = (b->b - a->b) / div;
		line->a = (b->a - a->a) / div;
	}
	else
	{
		line->r = 0;
		line->g = 0;
		line->b = 0;
		line->a = 0;
	}
}

static void	slope_less_than_one(mlx_image_t *img, t_drawing *l, t_point *a)
{
	uint32_t	c;
	int			i;

	i = -1;
	while (++i < abs(l->dx))
	{
		if (l->dx > 0)
			l->x++;
		else
			l->x--;
		if (l->p < 0)
			l->p = l->p + 2 * abs(l->dy);
		else
		{
			if (l->dy > 0)
				l->y++;
			else
				l->y--;
			l->p = l->p + 2 * abs(l->dy) - 2 * abs(l->dx);
		}
		c = combine_colors(l, a, i);
		if (l->x >= 1 && l->x <= WIDTH - 1 && l->y >= 1 && l->y <= HEIGHT - 1)
			mlx_put_pixel(img, l->x, l->y, c);
	}
}

static void	slope_more_than_one(mlx_image_t *img, t_drawing *l, t_point *a)
{
	uint32_t	c;
	int			i;

	i = -1;
	while (++i < abs(l->dy))
	{
		if (l->dy > 0)
			l->y++;
		else
			l->y--;
		if (l->p < 0)
			l->p = l->p + 2 * abs(l->dx);
		else
		{
			if (l->dx > 0)
				l->x++;
			else
				l->x--;
			l->p = l->p + 2 * abs(l->dx) - 2 * abs(l->dy);
		}
		c = combine_colors(l, a, i);
		if (l->x >= 1 && l->x <= WIDTH - 1 && l->y >= 1 && l->y <= HEIGHT - 1)
			mlx_put_pixel(img, l->x, l->y, c);
	}
}

static void	draw_line(mlx_image_t *img, t_point *a, t_point *b)
{
	t_drawing	line;

	line.dx = b->iso_x - a->iso_x;
	line.dy = b->iso_y - a->iso_y;
	get_steps(&line, a, b);
	line.x = a->iso_x;
	line.y = a->iso_y;
	if (abs(line.dx) > abs(line.dy))
	{
		line.p = 2 * abs(line.dy) - abs(line.dx);
		slope_less_than_one(img, &line, a);
	}
	else
	{
		line.p = 2 * abs(line.dx) - abs(line.dy);
		slope_more_than_one(img, &line, a);
	}
}

void	draw_image(mlx_image_t *img, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->depth - 2)
	{
		j = -1;
		while (++j < map->width - 2)
		{
			draw_line(img, &map->points[i][j], &map->points[i][j + 1]);
			draw_line(img, &map->points[i][j], &map->points[i + 1][j]);
		}
		draw_line(img, &map->points[i][j], &map->points[i + 1][j]);
	}
	j = -1;
	while (++j < map->width - 2)
		draw_line(img, &map->points[i][j], &map->points[i][j + 1]);
}
