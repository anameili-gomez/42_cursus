/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:26:53 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:58:12 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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

# define WHITE 0xFFFFFFFF

typedef struct s_file
{
	char			**points;
	struct s_file	*next;
}				t_file;

typedef struct s_drawing
{
	uint32_t	color;
	int			p;
	int			x;
	int			y;
	int			i;
}				t_drawing;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			iso_x;
	int			iso_y;
}				t_point;

typedef struct s_map
{
	int			width;
	int			depth;
	float		angle;
	int			x_max;
	int			x_min;
	int			y_max;
	int			y_min;
	t_point		**points;
}				t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
}				t_data;

//	===== MAP INTERPRETATION =====

int		get_width(char **points);
t_point	**get_points(int depth, int width, t_file *lst);
t_map	get_map(char *input);

//	===== DRAWING =====

void	create_image(mlx_image_t *img, t_map *map, float angle);
void	convert_to_2d(t_map *map);
void	find_max_and_min(t_map *map);

//	===== FREE AND EXIT =====

void	free_split(char **array);
void	free_lst(t_file *lst);
void	free_points(t_point **points, int n);
void	ft_exit(char *str, t_data *data, t_map *map, int n);

#endif