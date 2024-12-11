/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:45:57 by zblume            #+#    #+#             */
/*   Updated: 2024/06/07 13:13:34 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	mat_depth(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	return (i);
}

int	**init_collect(t_map *map)
{
	int	i;

	i = 0;
	map->collect_pos = malloc((sizeof(int *) * (map->c + 1)));
	if (map->collect_pos == NULL)
		return (NULL);
	while (i < map->c)
	{
		map->collect_pos[i] = malloc(sizeof(int) * 2);
		if (map->collect_pos[i] == NULL)
		{
			while (i > 0)
				free(map->collect_pos[--i]);
			free(map->collect_pos);
			return (NULL);
		}
		map->collect_pos[i][0] = 0;
		map->collect_pos[i][1] = 0;
		i++;
	}
	map->collect_pos[map->c] = NULL;
	return (map->collect_pos);
}

void	check_windowsize(t_data *data)
{
	if (data->w * IMG > WIDTH || (data->h + 2) * IMG > HEIGHT)
		map_error(WINDOW_ERROR, data);
	return ;
}
