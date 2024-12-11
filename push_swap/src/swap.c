/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:06:55 by zblume            #+#    #+#             */
/*   Updated: 2024/05/31 12:18:28 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_node **stack)
{
	int	temp;
	int	tempi;

	if (stack == NULL || *stack == NULL || (*stack)->below == NULL)
		return (0);
	temp = (*stack)->value;
	tempi = (*stack)->index;
	(*stack)->value = (*stack)->below->value;
	(*stack)->index = (*stack)->below->index;
	(*stack)->below->value = temp;
	(*stack)->below->index = tempi;
	return (1);
}

int	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
	return (1);
}

int	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
	return (1);
}

int	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	return (1);
}
