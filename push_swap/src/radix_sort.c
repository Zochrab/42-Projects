/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:56:02 by zblume            #+#    #+#             */
/*   Updated: 2024/06/06 12:13:52 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	bit_diff(t_node **stack_a, int bit)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if ((tmp->index >> bit & 1) == 1)
			return (1);
		tmp = tmp->below;
	}
	return (-1);
}

int	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		j;
	int		bits;

	i = 0;
	bits = count_bits(get_biggest(*stack_a)->index);
	while (i < bits)
	{
		j = stack_depth(*stack_a) + stack_depth(*stack_b);
		while (j > 0)
		{
			if (((*stack_a)->index >> i & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j--;
		}
		i++;
		while ((*stack_b))
			pa(stack_b, stack_a);
		if (is_sorted(*stack_a) == 1 && stack_depth(*stack_b) == 0)
			return (1);
	}
	return (1);
}
