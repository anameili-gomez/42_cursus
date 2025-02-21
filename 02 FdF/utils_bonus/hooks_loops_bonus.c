/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loops_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:52:36 by anagomez          #+#    #+#             */
/*   Updated: 2025/01/17 18:52:37 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fdf_bonus.h"

static void	clear_image(mlx_image_t *img, int depth, int width)
{
	int	i;
	int	j;

	i = -1;
	while (++i < depth)
	{
		j = -1;
		while (++j < width)
			mlx_put_pixel(img, j, i, 0x00000000);
	}
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = param;
	(void)xdelta;
	if (ydelta != 0)
	{
		clear_image(data->img, data->img->height, data->img->width);
		if (ydelta > 0)
			data->map->zoom *= 1.5;
		else if (ydelta < 0)
			data->map->zoom /= 1.5;
		redo_iso(data->map, 1);
		draw_image(data->img, data->map);
		if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
			ft_exit("Image to window error", data, data->map, 1);
	}
}

static void	rotation_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
		data->map->beta += 0.05;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
		data->map->beta -= 0.05;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		data->map->alpha -= 0.05;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
		data->map->alpha += 0.05;
}

static void	translation_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		data->map->x_offset -= 3;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		data->map->x_offset += 3;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		data->map->y_offset -= 3;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		data->map->y_offset += 3;
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(param);
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		clear_image(data->img, data->img->height, data->img->width);
		scaling_and_centering(data->map, 1);
		draw_image(data->img, data->map);
		if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
			ft_exit("Image to window error", data, data->map, 1);
	}
	else if (keydata.action == MLX_REPEAT)
	{
		rotation_hook(keydata, param);
		translation_hook(keydata, param);
		clear_image(data->img, data->img->height, data->img->width);
		redo_iso(data->map, 1);
		draw_image(data->img, data->map);
		if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
			ft_exit("Image to window error", data, data->map, 1);
	}
}
