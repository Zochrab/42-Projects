/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:37:08 by zblume            #+#    #+#             */
/*   Updated: 2024/07/12 18:26:31 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize(int argc, char **argv, t_node **stack_a)
{
	char	**str;

	if (argc == 2 && is_val_num(argv[1]) == 0)
		exit_error();
	str = clean_input(argv);
	argc = arr_length(str);
	error_checker(str);
	init_stack(stack_a, argc, str);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	initialize(argc, argv, &stack_a);
	if (stack_a == NULL)
		return (0);
	if (is_sorted(stack_a) != 1)
	{
		update_index_values(stack_a);
		if (stack_depth(stack_a) == 3)
			simple_sort(&stack_a);
		else if (stack_depth(stack_a) < 11)
			five_sort(&stack_a, &stack_b);
		else
			radix_sort(&stack_a, &stack_b);
	}
	free_stacks(&stack_a, &stack_b);
	return (0);
}
