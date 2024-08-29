/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:19:14 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/08/29 17:50:06 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	stack_is_sorted(t_node *stack)
{
	while (stack)
	{
		if (stack->next != NULL && stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	min_on_top(t_node **a)
{
	while ((*a)->value != get_min(*a)->value)
	{
		if (get_min(*a)->above_medium)
			ra(a);
		else
			rra(a);
	}
}

void	get_list_info(t_node *a, t_node *b)
{
	assign_index(a);
	assign_index(b);
	set_target_a(a, b);
	count_cost(a, b);
	find_best_to_move(a);
}

void	move_back_b(t_node *a, t_node *b)
{
	assign_index(a);
	assign_index(b);
	set_target_b(a, b);
}

void	sort_stack(t_node **a, t_node **b)
{
	int	a_size;

	a_size = list_size(*a);
	if (a_size > 3 && !stack_is_sorted(*a))
	{
		pb(a, b);
		a_size--;
	}

	if (a_size > 3 && !stack_is_sorted(*a))
	{
		pb(a, b);
		a_size--;
	}
	while (a_size > 3 && !stack_is_sorted(*a))
	{
		get_list_info(*a, *b);
		move_to_b(a, b);
	}
	perror("");
	tiny_sort(a);

	while (*b)
	{
		move_back_b(*a, *b);
		move_to_a(a, b);
	}
	assign_index(*a);
	min_on_top(a);
	ft_printf("new A is\n");
	print_list(*a);
}
