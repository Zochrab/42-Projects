/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prize_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:45:49 by zblume            #+#    #+#             */
/*   Updated: 2024/06/04 12:49:01 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_pos(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*bed;

	if ((*stack_a)->value < get_smallest(*stack_b)->value)
		return (get_biggest(*stack_b));
	tmp = (*stack_b);
	bed = get_smallest(*stack_b);
	while (tmp)
	{
		if (tmp->value > bed->value && tmp->value < (*stack_a)->value)
			bed = tmp;
		if (tmp->below == NULL)
			break ;
		tmp = tmp->below;
	}
	return (bed);
}

int	calc_prize(t_node *stack, t_node **stack_a, t_node **stack_b)
{
	int		i;
	t_node	*tmp;

	i = 1;
	tmp = find_pos(&stack, stack_b);
	if (node_depth(stack_a, stack) >= stack_depth(*stack_a) / 2)
		i = i + stack_depth(*stack_a) - node_depth(stack_a, stack);
	else
		i = i + node_depth(stack_a, stack);
	tmp = get_next_biggest(*stack_b, stack->value);
	if (tmp != NULL && node_depth(stack_b, tmp) >= stack_depth(*stack_b) / 2)
		i = i + stack_depth(*stack_b) - node_depth(stack_b, tmp);
	else
		i = i + node_depth(stack_b, tmp);
	return (i);
}

t_node	*best_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		i;
	int		prize;

	tmp = *stack_a;
	i = -1;
	while (tmp)
	{
		prize = calc_prize(tmp, stack_a, stack_b);
		if (prize < i || i == -1)
		{
			i = prize;
			tmp2 = tmp;
		}
		tmp = tmp->below;
	}
	return (tmp2);
}

void	eff_rotate(t_node *node, t_node **stack)
{
	int		rot_val;

	if (node_depth(stack, node) >= stack_depth(*stack) / 2)
		rot_val = node_depth(stack, node) - stack_depth(*stack);
	else
		rot_val = node_depth(stack, node);
	while (rot_val > 0)
	{
		if (node->stack == 'a')
			ra(stack);
		else
			rb(stack);
		rot_val--;
	}
	while (rot_val < 0)
	{
		if (node->stack == 'a')
			rra(stack);
		else
			rrb(stack);
		rot_val++;
	}
}

void	meff_rotate(t_node **s_a, t_node **s_b, t_node *n_a, t_node *n_b)
{
	int		rot_val_a;
	int		rot_val_b;

	rot_val_a = node_depth(s_a, n_a);
	if (rot_val_a >= stack_depth(*s_a) / 2)
		rot_val_a = rot_val_a - stack_depth(*s_a);
	rot_val_b = node_depth(s_b, n_b);
	if (rot_val_b >= stack_depth(*s_b) / 2)
		rot_val_b = rot_val_b - stack_depth(*s_b);
	while (rot_val_a > 0 && rot_val_b > 0)
	{
		rr(s_a, s_b);
		rot_val_a--;
		rot_val_b--;
	}
	while (rot_val_a < 0 && rot_val_b < 0)
	{
		rrr(s_a, s_b);
		rot_val_a++;
		rot_val_b++;
	}
	eff_rotate(n_a, s_a);
	eff_rotate(n_b, s_b);
}
