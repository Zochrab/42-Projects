/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:21:05 by zblume            #+#    #+#             */
/*   Updated: 2024/05/31 12:18:28 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_node *stack)
{
	t_node	*tmp;

	if (stack == NULL || stack->below == NULL)
		return (1);
	tmp = stack;
	while (tmp->below)
	{
		if (tmp->value > tmp->below->value)
			return (-1);
		tmp = tmp->below;
	}
	return (1);
}

t_node	*get_biggest(t_node *stack)
{
	t_node	*tmp;
	t_node	*big;

	tmp = stack;
	big = tmp;
	while (tmp)
	{
		tmp = tmp->below;
		if (tmp && big->value < tmp->value)
			big = tmp;
	}
	return (big);
}

t_node	*get_smallest(t_node *stack)
{
	t_node	*tmp;
	t_node	*small;

	tmp = stack;
	small = tmp;
	while (tmp)
	{
		tmp = tmp->below;
		if (tmp && small->value > tmp->value)
			small = tmp;
	}
	return (small);
}

int	has_negative(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value < 0)
			return (1);
		tmp = tmp->below;
	}
	return (0);
}

int	count_bits(int num)
{
	int	i;

	i = 0;
	while (num)
	{
		num = num >> 1;
		i++;
	}
	return (i);
}
