/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:41:37 by zblume            #+#    #+#             */
/*   Updated: 2024/06/06 13:27:31 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	end_game(t_data *data)
{
	if (data->collect == 0 && data->map->matrix[data->y][data->x] == 'E')
		ft_printf("%s\nMoves needed: %d\n", VICTORY, data->move);
	free_data(data);
	exit (0);
	return (0);
}
