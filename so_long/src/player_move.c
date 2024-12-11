/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:57:39 by zblume            #+#    #+#             */
/*   Updated: 2024/06/07 13:34:15 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_data *data)
{
	if (data->map->matrix[data->y - 1][data->x] != '1')
	{
		if (data->map->matrix[data->y - 1][data->x] == 'C')
		{
			data->collect--;
			data->map->matrix[data->y - 1][data->x] = '0';
		}
		data->y = data->y - 1;
		data->move++;
	}
}

void	move_down(t_data *data)
{
	if (data->map->matrix[data->y + 1][data->x] != '1')
	{
		if (data->map->matrix[data->y + 1][data->x] == 'C')
		{
			data->collect--;
			data->map->matrix[data->y + 1][data->x] = '0';
		}
		data->y = data->y + 1;
		data->move++;
	}
}

void	move_left(t_data *data)
{
	if (data->map->matrix[data->y][data->x - 1] != '1')
	{
		if (data->map->matrix[data->y][data->x - 1] == 'C')
		{
			data->collect--;
			data->map->matrix[data->y][data->x - 1] = '0';
		}
		data->x = data->x - 1;
		data->move++;
	}
}

void	move_right(t_data *data)
{
	if (data->map->matrix[data->y][data->x + 1] != '1')
	{
		if (data->map->matrix[data->y][data->x + 1] == 'C')
		{
			data->collect--;
			data->map->matrix[data->y][data->x + 1] = '0';
		}
		data->x = data->x + 1;
		data->move++;
	}
}

void	move_player(t_data *data, int key)
{
	if (key == KEY_UP || key == KEY_W)
		move_up(data);
	if (key == KEY_DOWN || key == KEY_S)
		move_down(data);
	if (key == KEY_LEFT || key == KEY_A)
		move_left(data);
	if (key == KEY_RIGHT || key == KEY_D)
		move_right(data);
	ft_printf(GAMESTATE, data->collect, data->move);
	if (data->collect == 0 && data->map->matrix[data->y][data->x] == 'E')
		end_game(data);
}
