/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:41:25 by zblume            #+#    #+#             */
/*   Updated: 2024/06/07 13:25:18 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	initialize_data(t_data *data, char *map_name)
{
	data->mlx = mlx_init();
	read_map(map_name, data);
	data->h = data->map->depth;
	data->w = ft_strlen(data->map->matrix[0]);
	data->collect = data->map->c;
	data->x = data->map->p_pos[1];
	data->y = data->map->p_pos[0];
	data->move = 0;
	check_windowsize(data);
	data->win = mlx_new_window
		(data->mlx, data->w * IMG, data->h * IMG, "so_long");
	mlx_key_hook(data->win, key_hook, data);
	data->img = malloc(sizeof(t_img));
	if (data->img == NULL)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (0);
	data = malloc(sizeof(t_data));
	initialize_data(data, argv[1]);
	assign_images(data);
	draw_map(data);
	mlx_hook(data->win, 17, 0, end_game, data);
	ft_printf("Collect all the Treasure to escape!\n");
	ft_printf(GAMESTATE, data->collect, data->move);
	mlx_loop(data->mlx);
	return (0);
}
