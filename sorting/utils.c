/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:23:44 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/09/02 18:26:17 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



t_node	*get_max(t_node **stack)
{
	// t_node	*current;
	// t_node	*highest;

	// if (!stack)
	// 	return (NULL);
	// current = stack;
	// highest = current;
	// while (current)
	// {
	// 	if (current->value > highest->value)
	// 		highest = current;
	// 	current = current->next;
	// }
	// return (highest);

	long	max;
	t_node	*tmp;
	t_node	*max_node;

	tmp = *stack;
	if (!tmp)
		return (NULL);
	max = LONG_MIN;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

t_node	*get_min(t_node **stack)
{
	long	min;
	t_node	*tmp;
	t_node	*min_node;

	tmp = *stack;
	if (!tmp)
		return (NULL);
	min = LONG_MAX;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
	// t_node	*current;
	// t_node	*min;

	// if (!stack)
	// 	return (NULL);
	// current = stack;
	// min = current;
	// while (current)
	// {
	// 	if (current->value < min->value)
	// 		min = current;
	// 	current = current->next;
	// }
	// return (min);
}


t_node	*find_best_to_move(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (tmp->cheapest)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
