/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:32:15 by zblume            #+#    #+#             */
/*   Updated: 2024/07/12 17:09:05 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_border(t_data *data)
{
	int		i;
	int		j;
	int		border;
	int		last;

	i = 0;
	border = ft_strlen(data->map->matrix[0]) - 1;
	last = data->map->depth - 1;
	while (data->map->matrix[i])
	{
		j = 0;
		while (data->map->matrix[i][j])
		{
			if (i == 0 || j == 0 || i == last || j == border)
				if (data->map->matrix[i][j] != '1')
					map_error(INVALID_MAP, data);
			j++;
		}
		i++;
	}
}

int	*find_entity(t_map *map, char c)
{
	int	i;
	int	j;
	int	*pos;

	i = 0;
	pos = malloc(sizeof(int) * 2);
	while (map->matrix[i])
	{
		j = 0;
		while (map->matrix[i][j])
		{
			if (map->matrix[i][j] == c)
			{
				pos[0] = i;
				pos[1] = j;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

char	**init_vis(t_map *map, char **vis)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->depth)
	{
		vis[i] = malloc(sizeof(char) * (ft_strlen(map->matrix[0]) + 1));
		if (vis[i] == NULL)
			return (NULL);
		i++;
	}
	i = 0;
	while (i < map->depth)
	{
		j = 0;
		while (j < ft_strlen(map->matrix[0]))
		{
			vis[i][j] = '0';
			j++;
		}
		vis[i][j] = '\0';
		i++;
	}
	return (vis);
}

int	dfs(t_map *map, int x, int y, char **vis)
{
	if (vis[map->exit_pos[0]][map->exit_pos[1]] == '1' && map->cleft == 0)
		return (1);
	if (x < 0 || x >= ft_strlen(map->matrix[0]) || y < 0 
		|| y >= map->depth
		|| vis[y][x] == '1' || map->matrix[y][x] == '1')
		return (0);
	vis[y][x] = '1';
	if (map->matrix[y][x] == 'C')
	{
		map->cleft--;
		map->collect_pos[map->cleft][0] = y;
		map->collect_pos[map->cleft][1] = x;
	}
	if (map->matrix[y][x] == 'E' && map->cleft == 0)
		return (1);
	if (dfs(map, x - 1, y, vis) 
		|| dfs(map, x, y - 1, vis) 
		|| dfs(map, x, y + 1, vis)
		|| dfs(map, x + 1, y, vis)) 
		return (1);
	return (0);
}

void	find_path(t_data *data, t_map *map)
{
	int		y;
	int		x;
	char	**vis;
	int		solvable;

	solvable = 1;
	map->p_pos = find_entity(map, 'P');
	x = map->p_pos[1];
	y = map->p_pos[0];
	map->exit_pos = find_entity(map, 'E');
	vis = malloc(sizeof(char *) * (map->depth));
	vis = init_vis(map, vis);
	map->collect_pos = init_collect(map);
	map->cleft = map->c;
	if (dfs(map, x, y, vis) == 0)
		solvable = 0;
	free_vis(map, vis);
	if (solvable == 0) 
		map_error(NO_SOLUTION, data);
}
