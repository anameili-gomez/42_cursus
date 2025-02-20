/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:46:23 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 15:45:59 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf_bonus.h"

static void	initiate_image(t_data *data, t_map *map)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);
	if (!data->mlx)
		ft_exit("MLX initiation fail", NULL, map, 1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		ft_exit("Image load fail", data, map, 1);
	draw_image(data->img, map);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		ft_exit("Image to window error", data, map, 1);
}

static void	hooks_and_loops(t_data *data)
{
	mlx_key_hook(data->mlx, my_keyhook, data);
	mlx_scroll_hook(data->mlx, my_scrollhook, data);
	mlx_close_hook(data->mlx, close_window, data);
	mlx_loop(data->mlx);
}

static void	closing(t_data *data)
{
	free_points(data->map->points, data->map->depth);
	mlx_delete_image(data->mlx, data->img);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_data	data;

	if (ac != 2)
		ft_exit("Format not matched", NULL, NULL, 1);
	map = get_map(av[1]);
	data.map = &map;
	initiate_image(&data, &map);
	hooks_and_loops(&data);
	closing(&data);
	return (0);
}
