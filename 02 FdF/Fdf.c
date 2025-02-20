/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:40:57 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 15:46:06 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

static void	close_window(void *param)
{
	t_data	*data;

	data = param;
	ft_exit(NULL, data, data->map, 0);
}

static void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(param);
}

static void	initiate_image(t_data *data, t_map *map)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);
	if (!data->mlx)
		ft_exit("MLX initiation fail", NULL, map, 1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		ft_exit("Image load fail", data, map, 1);
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
	create_image(data.img, &map, 0.523599);
	if (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0)
		ft_exit("Image to window error", &data, &map, 1);
	mlx_key_hook(data.mlx, my_keyhook, &data);
	mlx_close_hook(data.mlx, close_window, &data);
	mlx_loop(data.mlx);
	free_points(map.points, map.depth);
	mlx_delete_image(data.mlx, data.img);
	mlx_close_window(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
