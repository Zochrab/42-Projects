/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:34:46 by zblume            #+#    #+#             */
/*   Updated: 2024/06/06 12:14:10 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "printflibft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*above;
	struct s_node	*below;
	char			stack;
}t_node;

//Sorting Algorithm
int			is_sorted(t_node *stack);
int			simple_sort(t_node **stack_a);
int			five_sort(t_node **stack_a, t_node **stack_b);
int			radix_sort(t_node **stack_a, t_node **stack_b);
void		simplify_values(t_node *stack);
t_node		*find_bed(t_node **stack_a, t_node **stack_b);
int			efficient_rotate(t_node **stack_a);
void		turk_sort(t_node **stack_a, t_node **stack_b);

//Stack Ops
t_node		*init_stack(t_node **node, int argc, char **argv);
void		put(t_node **node, int value, int index);
int			print_stack(t_node *node);
int			fill_stack(t_node *node, int argc, char **argv);
t_node		*get_bottom(t_node **stack);
t_node		*get_biggest(t_node *stack);
t_node		*get_smallest(t_node *stack);
int			has_negative(t_node *stack);
t_node		*find_pos(t_node **stack_a, t_node **stack_b);
int			calc_prize(t_node *stack, t_node **stack_a, t_node **stack_b);
t_node		*best_move(t_node **stack_a, t_node **stack_b);
void		eff_rotate(t_node *node, t_node **stack);
void		meff_rotate(t_node **s_a, t_node **s_b, t_node *n_a, t_node *n_b);

//Swap
int			swap(t_node **stack);
int			sa(t_node **stack_a);
int			sb(t_node **stack_b);
int			ss(t_node **stack_a, t_node **stack_b);

//Push
int			push(t_node **source, t_node **dest);
int			pa(t_node **stack_a, t_node **stack_b);
int			pb(t_node **stack_a, t_node **stack_b);

//Rotate
int			rotate(t_node **stack);
int			ra(t_node **stack_a);
int			rb(t_node **stack_b);
int			rr(t_node **stack_a, t_node **stack_b);

//Reverse Rotate
int			reverse_rotate(t_node **stack);
int			rra(t_node **stack_a);
int			rrb(t_node **stack_b);
int			rrr(t_node **stack_a, t_node **stack_b);

//Error Checker
int			validate_input(char **argv);
int			check_dupes(char **argv);
char		**clean_input(char **argv);
size_t		arr_length(char **arr);
void		error_checker(char **argv);
int			is_val_num(char *str);
void		exit_error(void);

//Memory Management
void		free_stack(t_node *stack);
int			free_stacks(t_node **stack_a, t_node **stack_b);
void		free_strings(char **str);

//Misc
int			update_index_values(t_node *stack);
void		print_stacks(t_node **a, t_node **b);
int			stack_depth(t_node *stack);
int			count_bits(int num);
int			is_rev_sorted(t_node *stack);
int			node_depth(t_node **stack, t_node *node);
t_node		*get_next_biggest(t_node *stack, int value);

#endif
