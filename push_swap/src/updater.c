/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:36:25 by zblume            #+#    #+#             */
/*   Updated: 2024/05/31 12:18:28 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_next_biggest(t_node *stack, int value)
{
	t_node	*next_biggest; 
	t_node	*current;

	current = stack;
	next_biggest = NULL;
	while (current != NULL)
	{
		if (current->value > value)
			if (next_biggest == NULL || current->value < next_biggest->value)
				next_biggest = current;
		current = current->below;
	}
	return (next_biggest);
}

int	update_index_values(t_node *stack)
{
	int		i;
	int		min;
	t_node	*next;

	i = 0;
	min = get_smallest(stack)->value;
	next = get_smallest(stack);
	while (i < stack_depth(stack))
	{
		next->index = i;
		next = get_next_biggest(stack, min);
		if (next == NULL)
			return (0);
		i++;
		min = next->value;
	}
	return (1);
}

int	node_depth(t_node **stack, t_node *node)
{
	int		depth;
	t_node	**tmp;

	depth = 0;
	tmp = stack;
	if (stack == NULL || *stack == NULL || node == NULL)
		return (-1);
	while (*tmp != NULL && *tmp != node)
	{
		depth++;
		tmp = &((*tmp)->below);
	}
	if (*tmp == NULL)
		return (-1);
	return (depth);
}
