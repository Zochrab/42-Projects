/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:08:09 by zblume            #+#    #+#             */
/*   Updated: 2024/06/07 13:34:25 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	assign_images(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->img->ground = mlx_xpm_file_to_image(data->mlx,
			"assets/proper_assets/Free.xpm", &i, &j);
	data->img->wall = mlx_xpm_file_to_image(data->mlx,
			"assets/proper_assets/Wall.xpm", &i, &j);
	data->img->player = mlx_xpm_file_to_image(data->mlx,
			"assets/proper_assets/Player.xpm", &i, &j);
	data->img->exit = mlx_xpm_file_to_image(data->mlx,
			"assets/proper_assets/Exit.xpm", &i, &j);
	data->img->collect = mlx_xpm_file_to_image(data->mlx,
			"assets/proper_assets/Collectibles.xpm", &i, &j);
}

void	draw_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->player,
		data->x * IMG, data->y * IMG);
}

void	draw_collect(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < data->map->c)
	{
		x = data->map->collect_pos[i][1];
		y = data->map->collect_pos[i][0];
		if (data->map->matrix[y][x] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, data->img->collect,
				x * IMG, y * IMG);
		i++;
	}
}

void	draw_world(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->w)
	{
		j = 0;
		while (j < data->h)
		{
			if (data->map->matrix[j][i] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img->wall, 
					i * IMG, j * IMG);
			else if (data->map->matrix[j][i] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img->exit, 
					i * IMG, j * IMG);
			else
				mlx_put_image_to_window(data->mlx, data->win, 
					data->img->ground, i * IMG, j * IMG);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *data)
{
	draw_world(data);
	draw_player(data);
	draw_collect(data);
}
