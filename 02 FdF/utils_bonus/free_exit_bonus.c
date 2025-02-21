/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:29:53 by anagomez          #+#    #+#             */
/*   Updated: 2025/01/17 13:08:00 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fdf_bonus.h"

void	close_window(void *param)
{
	t_data	*data;

	data = param;
	ft_exit(NULL, data, data->map, 0);
}

void	free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_lst(t_file *lst)
{
	t_file	*to_free;

	while (lst)
	{
		free_split(lst->points);
		to_free = lst;
		lst = lst->next;
		free(to_free);
	}
}

void	free_points(t_point **points, int n)
{
	int	i;

	i = 0;
	if (!points)
		return ;
	while (i < n)
	{
		if (points[i])
			free(points[i]);
		i++;
	}
	free(points);
}

void	ft_exit(char *str, t_data *data, t_map *map, int n)
{
	if (str)
		ft_printf("%s\n", str);
	if (map && map->points)
		free_points(map->points, map->depth);
	if (data && data->img)
		mlx_delete_image(data->mlx, data->img);
	if (data && data->mlx)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	exit(n);
}
