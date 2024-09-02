/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:53:10 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/09/02 20:13:50 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_index(t_node **stack)
{
	int		i;
	int		medium;
	t_node	*tmp;

	i = 0;
	tmp = (*stack);
	if (!tmp)
		return ;
	medium = list_size(tmp) / 2;
	while (tmp)
	{
		tmp->index = i;
		if (i <= medium)
			tmp->above_medium = true;
		else
			tmp->above_medium = false;
		tmp = tmp->next;
		i++;
	}
}

void	set_target_a(t_node **a, t_node **b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	t_node	*target;
	long	best_match;

	tmp_a = *a;
	while (tmp_a)
	{
		best_match = LONG_MIN;
		tmp_b = *b;
		while (tmp_b)
		{
			if (tmp_b->value < tmp_a->value && tmp_b->value > best_match)
			{
				best_match = tmp_b->value;
				target = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (best_match == LONG_MIN)
			tmp_a->target = get_max(b);
		else
			tmp_a->target = target;
		tmp_a = tmp_a->next;
	}
}

void	set_target_b(t_node **a, t_node **b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	t_node	*target;
	long	best_match;

	tmp_b = *b;
	while (tmp_b)
	{
		best_match = LONG_MAX;
		tmp_a = *a;
		while (tmp_a)
		{
			if (tmp_a->value > tmp_b->value && tmp_a->value < best_match)
			{
				best_match = tmp_a->value;
				target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (best_match == LONG_MAX)
			tmp_b->target = get_min(a);
		else
			tmp_b->target = target;
		tmp_b = tmp_b->next;
	}
}

void	count_cost_a(t_node **a, t_node **b)
{
	int		a_size;
	int		b_size;
	t_node	*tmp_a;

	a_size = list_size(*a);
	b_size = list_size(*b);
	tmp_a = *a;
	while (tmp_a)
	{
		(tmp_a)->push_cost = (tmp_a)->index;
		if (!(tmp_a->above_medium))
			tmp_a->push_cost = a_size - (tmp_a->index);
		if (tmp_a->target->above_medium)
			tmp_a->push_cost += tmp_a->target->index;
		else
			tmp_a->push_cost += b_size - (tmp_a->target->index);
		tmp_a = tmp_a->next;
	}
}

void	set_best_to_move(t_node **stack)
{
	long	cheapest;
	t_node	*best_to_move;
	t_node	*tmp;

	tmp = *stack;
	if (!tmp)
		return ;
	cheapest = LONG_MAX;
	while (tmp)
	{
		if (tmp->push_cost < cheapest)
		{
			cheapest = tmp->push_cost;
			best_to_move = tmp;
		}
		tmp = tmp->next;
	}
	best_to_move->cheapest = true;
}
