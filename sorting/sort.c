/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:19:14 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/09/03 12:46:37 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	stack_is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	min_on_top(t_node **a)
{
	t_node	*tmp;

	tmp = get_min(a);
	while ((*a)->value != tmp->value)
	{
		if (tmp->above_medium)
			ra(a);
		else
			rra(a);
	}
}

void	get_stack_info(t_node **a, t_node **b)
{
	assign_index(a);
	assign_index(b);
	set_target_a(a, b);
	count_cost_a(a, b);
	set_best_to_move(a);
}

void	move_back_b(t_node **a, t_node **b)
{
	assign_index(a);
	assign_index(b);
	set_target_b(a, b);
}

void	sort_stack(t_node **a, t_node **b)
{
	int	a_size;

	a_size = list_size(*a);
	if (a_size-- > 3 && !stack_is_sorted(*a))
		pb(a, b);
	if (a_size-- > 3 && !stack_is_sorted(*a))
		pb(a, b);
	while (a_size-- > 3 && !stack_is_sorted(*a))
	{
		get_stack_info(a, b);
		move_to_b(a, b);
	}
	tiny_sort(a);
	while (*b)
	{
		move_back_b(a, b);
		move_to_a(a, b);
	}
	assign_index(a);
	min_on_top(a);
}
