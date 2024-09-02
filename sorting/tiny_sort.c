/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:53:34 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/09/02 18:32:17 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	tiny_sort(t_node **stack)
{
	t_node	*highest;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if ((*stack)->next->next == NULL)
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
		return ;
	}
	highest = get_max(stack);
	if (*stack == highest)
		ra(stack);
	else if ((*stack)->next == highest)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}
