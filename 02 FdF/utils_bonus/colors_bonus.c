/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:05:24 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 15:46:25 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fdf_bonus.h"

uint32_t	combine_colors(t_drawing *line, t_point *a, int i)
{
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;
	uint32_t	alpha;

	red = ((uint32_t)(a->r + line->r * i) & 0xFF) << 24;
	green = ((uint32_t)(a->g + line->g * i) & 0xFF) << 16;
	blue = ((int)(a->b + line->b * i) & 0xFF) << 8;
	alpha = (int)(a->a + line->a * i) & 0xFF;
	return (red | green | blue | alpha);
}

static uint32_t	ft_atoi_hex(char *c)
{
	uint32_t	n;
	int			i;

	n = 0;
	i = 0;
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9')
			n = (n << 4) | (c[i] - '0');
		else if (c[i] >= 'A' && c[i] <= 'Z')
			n = (n << 4) | (c[i] - 'A' + 10);
		else if (c[i] >= 'a' && c[i] <= 'z')
			n = (n << 4) | (c[i] - 'a' + 10);
		else
			return (0xFFFFFFFF);
		i++;
	}
	return (n);
}

static uint32_t	normalize_color(uint32_t color)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = 0;
	g = 0;
	b = 0;
	if (color & 0xFF0000)
		r = (color >> 16) & 0xFF;
	if (color & 0xFF00)
		g = (color >> 8) & 0xFF;
	if (color & 0xFF)
		b = color & 0xFF;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

void	get_colors(t_point *point, char *c)
{
	uint32_t	color;

	if (!c)
		color = 0xFFFFFFFF;
	else
	{
		color = ft_atoi_hex(c + 3);
		color = normalize_color(color);
	}
	point->r = (color >> 24) & 0xFF;
	point->g = (color >> 16) & 0xFF;
	point->b = (color >> 8) & 0xFF;
	point->a = color & 0xFF;
}
