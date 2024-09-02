/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:06:00 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/09/02 12:53:08 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **first, t_node **second)
{
	t_node	*current_s;

	if (!*second)
		return ;
	current_s = *second;
	*second = current_s->next;
	if (*second)
		(*second)->prev = NULL;
	current_s->next = *first;
	current_s->prev = NULL;
	if (*first)
		(*first)->prev = current_s;
	*first = current_s;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
