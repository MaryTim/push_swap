/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:34:26 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/08/29 17:35:39 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "libftPrintfGnl/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# define PUSH_SWAP_H

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
	int				index;
	int				push_cost;
	bool			above_medium;
}	t_node;

void	print_error_message(char *message1, char *message2);
bool	check_min_max_int(long l);
bool	only_numbers(char **argv, int i);
int		*validation_and_result(int argc, char **argv);
long	ft_atol(const char *nptr);
t_node	*get_stack(int argc, char **argv);
int		count_elements(char	**split_res);
void	free_list(t_node *head);
int		list_size(t_node *my_node);
void	swap(t_node **my_node);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	rotate(t_node **my_node);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	reverse_rotate(t_node **head);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	push(t_node **first, t_node **second);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
t_node	*convert_to_list(int *array, int size);
void	free_array(char **ptr);
void	tiny_sort(t_node **stack);
bool	stack_is_sorted(t_node *stack);
void	sort_stack(t_node **a, t_node **b);
t_node	*get_highest(t_node *stack);
void	get_list_info(t_node *a, t_node *b);
void	move_to_a(t_node **a, t_node **b);
void	move_to_b(t_node **a, t_node **b);
void	assign_index(t_node *stack);
t_node	*get_min(t_node *stack);
void	count_cost(t_node *a, t_node *b);
t_node	*get_highest(t_node *stack);
t_node	*find_best_to_move(t_node *stack);
void	set_target_a(t_node *a, t_node *b);
void	set_target_b(t_node *a, t_node *b);

#endif