/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:13:47 by zblume            #+#    #+#             */
/*   Updated: 2024/05/31 12:18:28 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_node **source, t_node **dest)
{
	t_node	*tmp;

	if (source == NULL)
		return (0);
	tmp = (*source);
	if (tmp->stack == 'a')
		tmp->stack = 'b';
	else
		tmp->stack = 'a';
	if (tmp->below != NULL)
	{
		(*source) = (*source)->below;
		(*source)->above = NULL;
	}
	else
		(*source) = NULL;
	if ((*dest) != NULL)
		(*dest)->above = tmp;
	tmp->below = (*dest);
	tmp->above = NULL;
	(*dest) = tmp;
	return (1);
}

int	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
	return (1);
}

int	pa(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
	return (1);
}
