/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:34:16 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/09/02 20:06:36 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_node *my_node)
{
	t_node	*current;

	current = my_node;
	while (current)
	{
		ft_printf("node is %d\n", current->value);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
	{
		print_error_message("Please enter some arguments ",
			"you'd like to sort");
		return (-1);
	}
	else
	{
		a = get_stack(argc, argv);
		b = NULL;
		if (!stack_is_sorted(a))
		{
			if (list_size(a) <= 3 && list_size(a) >= 2)
				tiny_sort(&a);
			else
				sort_stack(&a, &b);
		}
		free_list(b);
		free_list(a);
	}
}
