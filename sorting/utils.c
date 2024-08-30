/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:23:44 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/08/29 17:43:48 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_index(t_node *stack)
{
	int	i;
	int	medium;

	i = 0;
	if (!stack)
		return ;
	medium = list_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= medium)
			stack->above_medium = true;
		else
			stack->above_medium = false;
		stack = stack->next;
		i++;
	}
}

t_node	*get_highest(t_node *stack)
{
	t_node	*current;
	t_node	*highest;

	if (!stack)
		return (NULL);
	current = stack;
	highest = current;
	while (current)
	{
		if (current->value > highest->value)
			highest = current;
		current = current->next;
	}
	return (highest);
}

t_node	*get_min(t_node *stack)
{
	t_node	*current;
	t_node	*min;

	if (!stack)
		return (NULL);
	current = stack;
	min = current;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

void	count_cost(t_node *a, t_node *b)
{
	int	a_size;
	int	b_size;

	a_size = list_size(a);
	b_size = list_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_medium)
			a->push_cost = a_size - a->index;
		if (a->target->above_medium)
			a->push_cost += a->target->index;
		else
			a->push_cost += b_size - a->target->index;
		a = a->next;
	}
}

t_node	*find_best_to_move(t_node *stack)
{
	long	cheapest;
	t_node	*best_to_move;

	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			best_to_move = stack;
		}
		stack = stack->next;
	}
	return (best_to_move);
}
