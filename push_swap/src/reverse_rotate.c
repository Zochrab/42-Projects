/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:21:19 by zblume            #+#    #+#             */
/*   Updated: 2024/05/31 12:18:28 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	reverse_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*end;

	if (!stack || !*stack || !(*stack)->below)
		return (0);
	tmp = get_bottom(stack);
	end = tmp->above;
	if (!tmp || !end)
		return (0);
	tmp->below = *stack;
	tmp->above = NULL;
	end->below = NULL;
	(*stack)->above = tmp;
	(*stack) = tmp;
	return (1);
}

int	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
	return (1);
}
