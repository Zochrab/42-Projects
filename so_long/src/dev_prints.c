/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_prints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:51:47 by zblume            #+#    #+#             */
/*   Updated: 2024/04/16 13:05:09 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_map *map)
{
	int		i;
	int		j;
	char	**str;

	str = map->matrix;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			printf("%c", str[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	print_vis(char **vis)
{
	int		i;
	int		j;

	i = 0;
	while (vis[i])
	{
		j = 0;
		while (vis[i][j])
		{
			printf("%c", vis[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	print_collectibles(int **collect, int c)
{
	int		i;

	i = 0;
	while (i < c)
	{
		ft_printf("Collectible at: %d %d\n", collect[i][0], collect[i][1]);
		i++;
	}
}
