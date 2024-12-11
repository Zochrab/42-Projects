/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:42:24 by zblume            #+#    #+#             */
/*   Updated: 2024/06/04 12:52:51 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int key, t_data *data)
{
	if (key == KEY_ESC || key == KEY_Q)
		end_game(data);
	move_player(data, key);
	draw_map(data);
	return (0);
}
