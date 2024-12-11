/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxillary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:47:53 by zblume            #+#    #+#             */
/*   Updated: 2024/06/27 11:46:11 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



int	is_rev_sorted(t_node *stack)
{
	t_node	*tmp;

	if (stack == NULL || stack->below == NULL)
		return (1);
	tmp = stack;
	while (tmp->below)
	{
		if (tmp->value < tmp->below->value)
			return (-1);
		tmp = tmp->below;
	}
	return (1);
}

void	print_stacks(t_node **a, t_node **b)
{
	t_node	*t_a;
	t_node	*t_b;

	t_a = *a;
	t_b = *b;
	ft_printf("stack a:        stack b:\n");
	while (t_a != NULL || t_b != NULL)
	{
		if (t_a != NULL)
		{
			ft_printf("%d", t_a->value);
			t_a = t_a->below;
		}
		if (t_b != NULL)
		{
			ft_printf("                %d", t_b->value);
			t_b = t_b->below;
		}
		ft_printf("\n");
	}
}

int	stack_depth(t_node *stack)
{
	int		depth;
	t_node	*tmp;

	tmp = stack;
	depth = 0;
	while (tmp)
	{
		depth++;
		if (tmp->below == NULL)
			break ;
		tmp = tmp->below;
	}
	return (depth);
}

int	is_val_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if ((str[i] < '0' || str[i] > '9') && !(str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

void	exit_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}
