/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:35:25 by zblume            #+#    #+#             */
/*   Updated: 2024/05/31 12:18:28 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_strings(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_node	*get_bottom(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp->below)
		tmp = tmp->below;
	return (tmp);
}

void	free_stack(t_node *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack;
	while (current != NULL)
	{
		next = current->below;
		current->below = NULL;
		current->above = NULL;
		current->value = 0;
		current->index = 0;
		current->stack = 0;
		free(current);
		current = next;
	}
}

int	free_stacks(t_node **stack_a, t_node **stack_b)
{
	free_stack(*stack_a);
	free_stack(*stack_b);
	return (0);
}
