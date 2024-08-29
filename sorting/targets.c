/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:31:12 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/08/29 15:34:32 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->value > best_match)
			{
				best_match = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MAX)
			a->target = get_highest(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	set_target_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target;
		b = b->next;
	}
}
