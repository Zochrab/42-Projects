/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:19:14 by zblume            #+#    #+#             */
/*   Updated: 2024/05/31 12:18:28 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*init_stack(t_node **node, int argc, char **argv)
{
	int		i;
	t_node	*element;
	t_node	*top;
	int		value;

	i = 0;
	element = NULL;
	if (argc < 2)
		return (NULL);
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		free(argv[i]);
		put(&element, value, i);
		if (i == 0)
			top = element;
		i++;
	}
	*node = top;
	free(argv);
	return (top);
}

void	put(t_node **node, int value, int index)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
	{
		ft_putendl_fd("Error", 2);
		free_stack(*node);
		exit(EXIT_FAILURE);
	}
	new->value = value;
	new->above = *node;
	new->index = index;
	new->stack = 'a';
	new->below = NULL;
	if (*node != NULL)
		(*node)->below = new;
	*node = new;
}

int	print_node_info(t_node *node)
{
	if (node == NULL)
		ft_putendl_fd("Error", 2);
	else
	{
		ft_printf("value: %d\n", node->value);
		ft_printf("index: %d\n", node->index);
		ft_printf("stack: %c\n", node->stack);
		ft_printf("above: %p\n", node->above);
		ft_printf("below: %p\n", node->below);
		ft_printf("current: %p\n", node);
		ft_printf("\n");
	}
	return (0);
}

int	print_stack(t_node *node)
{
	if (node == NULL)
		return (-1);
	print_node_info(node);
	ft_printf("\n");
	print_stack(node->below);
	return (0);
}
