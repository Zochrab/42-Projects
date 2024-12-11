/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:25:22 by zblume            #+#    #+#             */
/*   Updated: 2024/05/31 12:18:28 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	simple_sort(t_node **stack_a)
{
	int		tval;
	int		mval;
	int		bval;

	tval = (*stack_a)->index;
	mval = (*stack_a)->below->index;
	bval = (*stack_a)->below->below->index;
	if (tval < bval && bval < mval)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (mval < tval && tval < bval)
		sa(stack_a);
	if (bval < tval && tval < mval)
		rra(stack_a);
	if (bval < mval && mval < tval)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (mval < bval && bval < tval)
		ra(stack_a);
	return (0);
}

t_node	*find_bed(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*bed;

	if ((*stack_b)->value > get_biggest(*stack_a)->value)
		return (get_smallest(*stack_a));
	tmp = (*stack_a);
	bed = get_biggest(*stack_a);
	while (tmp)
	{
		if (bed->value > tmp->value && tmp->value > (*stack_b)->value)
			bed = tmp;
		if (tmp->below == NULL)
			break ;
		tmp = tmp->below;
	}
	return (bed);
}

int	efficient_rotate(t_node **stack_a)
{
	int		depth;
	int		midpoint;
	int		index_tmp;
	t_node	*tmp;

	tmp = get_smallest(*stack_a);
	depth = stack_depth(*stack_a);
	midpoint = depth / 2;
	index_tmp = node_depth(stack_a, tmp);
	if (index_tmp > midpoint)
		while ((*stack_a)->value != tmp->value)
			rra(stack_a);
	else
		while ((*stack_a)->value != tmp->value)
			ra(stack_a);
	return (0);
}

int	five_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (is_sorted(*stack_a) == 1)
		return (0);
	if (stack_depth(*stack_a) == 2 && is_sorted(*stack_a) == -1)
	{
		sa(stack_a);
		return (0);
	}
	while (stack_depth(*stack_a) > 3) 
		pb(stack_a, stack_b);
	simple_sort(stack_a);
	tmp = find_bed(stack_a, stack_b);
	while (stack_depth(*stack_b) > 0)
	{
		if ((*stack_a)->value == find_bed(stack_a, stack_b)->value)
			pa(stack_b, stack_a);
		else
			ra(stack_a);
	}
	efficient_rotate(stack_a);
	return (0);
}
