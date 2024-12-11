/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:53:52 by zblume            #+#    #+#             */
/*   Updated: 2024/05/31 12:18:28 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*i;

	if ((*stack) == NULL || (*stack)->below == NULL)
		return (0);
	tmp = (*stack);
	(*stack) = (*stack)->below;
	(*stack)->above = NULL;
	tmp->below = NULL;
	i = (*stack);
	while (i->below != NULL)
		i = i->below;
	i->below = tmp;
	tmp->above = i;
	return (1);
}

int	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
	return (1);
}

int	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	return (1);
}
