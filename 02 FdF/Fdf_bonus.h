/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:46:16 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:58:19 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include "get_next_line_bonus.h"
# include "ft_printf.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_drawing
{
	int		p;
	int		x;
	int		y;
	int		dx;
	int		dy;
	float	r;
	float	g;
	float	b;
	float	a;
}				t_drawing;

typedef struct s_file
{
	char			**points;
	struct s_file	*next;
}				t_file;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			iso_x;
	int			iso_y;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;
}				t_point;

typedef struct s_map
{
	int			width;
	int			depth;
	float		alpha;
	float		beta;
	float		zoom;
	float		x_offset;
	float		y_offset;
	int			x_max;
	int			x_min;
	int			y_max;
	int			y_min;
	float		center_x;
	float		center_y;
	t_point		**points;
}				t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
}				t_data;

//	===== MAP INTERPRETATION =====

int			get_width(char **points);
t_point		**get_points(int depth, int width, t_file *lst);
void		get_colors(t_point *point, char *color);
void		scaling_and_centering(t_map *map);
void		find_max_and_min(t_map *map);
t_map		get_map(char *file);

//	===== DRAWING AND HOOKS =====

uint32_t	combine_colors(t_drawing *line, t_point *a, int i);
void		draw_image(mlx_image_t *img, t_map *map);
void		close_window(void *param);
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		redo_iso(t_map *map, int time);

//	===== FREE AND EXIT =====

void		free_split(char **array);
void		free_lst(t_file *lst);
void		free_points(t_point **points, int n);
void		ft_exit(char *str, t_data *data, t_map *map, int n);

#endif