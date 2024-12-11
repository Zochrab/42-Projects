/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:42:38 by zblume            #+#    #+#             */
/*   Updated: 2024/06/07 13:34:34 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_file(char *argv, t_data *data)
{
	if (ft_strncmp(argv + ft_strlen(argv) - 4, ".ber", 4) != 0)
		map_error(NOT_BER_FILE, data);
	data->map->fd = open(argv, O_RDONLY);
	if (data->map->fd < 0)
		map_error(READ_ERROR, data);
}

void	get_map(t_data *data)
{
	char		*line;
	const char	*temp;
	char		**matrix;
	char		*nline;
	int			fd;

	fd = data->map->fd;
	line = get_next_line(fd);
	if (!line)
		map_error(READ_ERROR, data);
	while (1)
	{
		temp = (const char *)get_next_line(fd);
		if (temp == NULL)
			break ;
		nline = ft_strjoin((const char *)line, temp);
		free((char *)line);
		line = nline;
		free((char *)temp);
		data->map->depth++;
	}
	matrix = ft_split(line, '\n');
	free(line);
	data->map->matrix = matrix;
	return ;
}

void	is_valid_map(t_data *data)
{
	int		i;
	int		j;
	int		line_len;
	t_map	*map;

	map = data->map;
	i = 0;
	line_len = ft_strlen(map->matrix[0]);
	while (map->matrix[i])
	{
		j = 0;
		while (map->matrix[i][j])
		{
			if (map->matrix[i][j] == 'C' || map->matrix[i][j] == 'E'
				|| map->matrix[i][j] == 'P' || map->matrix[i][j] == '0'
				|| map->matrix[i][j] == '1')
				j++;
			else
				map_error(WRONG_SYMBOLS, data);
		}
		if (ft_strlen(map->matrix[i]) != line_len)
			map_error(INVALID_MAP, data);
		i++;
	}
}

void	count_entities(t_data *data, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->p = 0;
	map->e = 0;
	map->c = 0;
	while (map->matrix[i])
	{
		j = 0;
		while (map->matrix[i][j])
		{
			if (map->matrix[i][j] == 'P')
				map->p++;
			if (map->matrix[i][j] == 'E')
				map->e++;
			if (map->matrix[i][j] == 'C')
				map->c++;
			j++;
		}
		i++;
	}
	if (map->p != 1 || map->e != 1 || map->c < 1)
		map_error(INVALID_MAP, data);
}

void	*read_map(char *argv, t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (data->map == NULL)
		return (NULL);
	data->map->depth = 1;
	data->map->matrix = NULL;
	data->map->c = 0;
	data->map->cleft = 0;
	data->map->e = 0;
	data->map->p = 0;
	data->map->p_pos = NULL;
	data->map->exit_pos = NULL;
	data->map->collect_pos = NULL;
	data->map->fd = -1;
	open_file(argv, data);
	get_map(data);
	close(data->map->fd);
	is_valid_map(data);
	count_entities(data, data->map);
	check_border(data);
	find_path(data, data->map);
	return (data->map);
}
