/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:20:46 by zblume            #+#    #+#             */
/*   Updated: 2024/06/03 15:09:24 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_images(t_data *data)
{
	if (data->img->player != NULL)
		mlx_destroy_image(data->mlx, data->img->player);
	if (data->img->wall != NULL)
		mlx_destroy_image(data->mlx, data->img->wall);
	if (data->img->ground != NULL)
		mlx_destroy_image(data->mlx, data->img->ground);
	if (data->img->exit != NULL)
		mlx_destroy_image(data->mlx, data->img->exit);
	if (data->img->collect != NULL)
		mlx_destroy_image(data->mlx, data->img->collect);
	free(data->img);
}

void	free_vis(t_map *map, char **vis)
{
	int	i;
	int	depth;

	i = 0;
	depth = map->depth;
	while (i < depth)
	{
		free(vis[i]);
		vis[i] = NULL;
		i++;
	}
	free(vis);
}

void	free_matrix(t_map *map)
{
	int	i;
	int	rows;

	i = 0;
	rows = mat_depth(map->matrix);
	while (i < rows)
	{
		free(map->matrix[i]);
		map->matrix[i] = NULL;
		i++;
	}
	free(map->matrix);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	if (map->matrix != NULL)
		free_matrix(map);
	i = 0;
	if (map->collect_pos != NULL)
	{
		while (map->collect_pos[i])
			free(map->collect_pos[i++]);
		free(map->collect_pos);
		free(map->p_pos);
		free(map->exit_pos);
	}
	free(map);
}

void	free_data(t_data *data)
{
	if (data->map != NULL)
		free_map(data->map);
	free_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data);
}
