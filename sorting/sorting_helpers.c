/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:59:58 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/08/29 17:16:04 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_2(t_node **a, t_node **b, t_node *best_to_move)
{
	while (*a != best_to_move && *b != best_to_move->target)
		rr(a, b);
	assign_index(*a);
	assign_index(*b);
}

void	rev_rotate_2(t_node **a, t_node **b, t_node *best_to_move)
{
	while (*a != best_to_move && *b != best_to_move->target)
		rrr(a, b);
	assign_index(*a);
	assign_index(*b);
}

void	check_top_nodes(t_node **stack, t_node *top, char name)
{
	// 	assign_index(*stack);
	// 	while (top->index != 0)
	// {
	// 	assign_index(*stack);
	// 	if (name == 'b')
	// 		ft_printf("top index is %i\n", top->index);
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->above_medium)
				ra(stack);
			else
				rra(stack);
		}
		if (name == 'b')
		{
			if (top->above_medium)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_to_b(t_node **a, t_node **b)
{
	t_node	*best_to_move;

	best_to_move = find_best_to_move(*a);
	if (best_to_move->above_medium && best_to_move->target->above_medium)
		rotate_2(a, b, best_to_move);
	else if (!best_to_move->above_medium && !best_to_move->target->above_medium)
		rev_rotate_2(a, b, best_to_move);
	check_top_nodes(a, best_to_move, 'a');
	check_top_nodes(b, best_to_move->target, 'b');
	pb(a, b);
}

void	move_to_a(t_node **a, t_node **b)
{
	check_top_nodes(a, (*b)->target, 'a');
	pa(a, b);
}
