/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:41:53 by zblume            #+#    #+#             */
/*   Updated: 2024/06/27 11:45:19 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	arr_length(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	validate_input(char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < arr_length(argv))
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][0] != '-')
				return (-1);
			if (is_val_num(argv[i]) == 0)
				return (-1); 
			j++;
		}
		if (ft_strlen(argv[i]) > 11 || ft_atoi(argv[i]) > 2147483647 
			|| ft_atoi(argv[i]) < -2147483648)
			return (-1);
		i++;
	}
	return (0);
}

int	check_dupes(char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < arr_length(argv))
	{
		j = i + 1;
		while (j < arr_length(argv))
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**clean_input(char **argv)
{
	char	*result;
	char	**split_result; 
	int		i;
	char	*temp;

	i = 1;
	result = ft_strdup("");
	while (argv[i])
	{
		temp = ft_strjoin(result, argv[i]);
		free (result);
		result = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	split_result = ft_split(result, ' ');
	free(result);
	return (split_result);
}

void	error_checker(char **argv)
{
	if (validate_input(argv) == 0 && check_dupes(argv) == 0)
		return ;
	else
	{
		ft_putendl_fd("Error", 2);
		free_strings(argv);
		exit(0);
	}
	return ;
}
