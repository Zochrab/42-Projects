/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:44:13 by zblume            #+#    #+#             */
/*   Updated: 2024/06/03 15:26:37 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_handler(int num)
{
	ft_printf("Error!\n");
	if (num == READ_ERROR)
		ft_printf("File cannot be read!\n");
	if (num == NOT_BER_FILE)
		ft_printf("Not a .ber file\n");
	if (num == INVALID_MAP)
		ft_printf("Invalid Map!\n");
	if (num == WRONG_SYMBOLS)
		ft_printf("Wrong symbols in map!\n");
	if (num == NO_SOLUTION)
		ft_printf("No solution!\n");
	if (num == WINDOW_ERROR)
		ft_printf("Map is too big!\n");
	return ;
}

void	map_error(int num, t_data *data)
{
	error_handler(num);
	if (data != NULL)
	{
		free_map(data->map);
		mlx_destroy_display(data->mlx);
		free(data);
	}
	exit (0);
}
