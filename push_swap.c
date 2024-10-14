/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:34:16 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/09/03 12:46:51 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_2_and_more_args(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = get_stack(argc, argv);
	b = NULL;
	if (!a)
		return (-1);
	else
	{
		if (!stack_is_sorted(a))
		{
			if (list_size(a) <= 3 && list_size(a) >= 2)
				tiny_sort(&a);
			else
				sort_stack(&a, &b);
		}
		free_list(a);
		return (0);
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		print_error("Please enter some arguments ", "you'd like to sort");
		return (-1);
	}
	else
		handle_2_and_more_args(argc, argv);
}
