/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:16:13 by zblume            #+#    #+#             */
/*   Updated: 2024/05/31 12:18:28 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	turk_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_depth(*stack_a) > 0)
	{
		tmp = best_move(stack_a, stack_b);
		tmp2 = find_pos(&tmp, stack_b);
		meff_rotate(stack_a, stack_b, tmp, tmp2);
		pb(stack_a, stack_b);
	}
	while (stack_depth(*stack_b) > 0)
		pa(stack_b, stack_a);
	efficient_rotate(stack_a);
}
