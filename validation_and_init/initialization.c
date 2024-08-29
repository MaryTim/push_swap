/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:12:59 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/08/29 15:35:30 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *) malloc (sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->above_medium = false;
	return (new_node);
}

t_node	*convert_to_list(int *array, int size)
{
	int		i;
	t_node	*head;
	t_node	*current;
	t_node	*new_node;

	if (size == 0)
		return (NULL);
	head = create_node(array[0]);
	current = head;
	i = 1;
	while (i < size)
	{
		new_node = create_node(array[i]);
		current->next = new_node;
		new_node->prev = current;
		current = new_node;
		i++;
	}
	return (head);
}

t_node	*get_stack(int argc, char **argv)
{
	int		*res;
	t_node	*head;
	char	**split;

	res = validation_and_result(argc, argv);
	split = ft_split(argv[1], ' ');
	if (res)
	{
		if (argc == 2)
			head = convert_to_list(res,
					count_elements(split));
		else
			head = convert_to_list(res, argc - 1);
		free(res);
		free_array(split);
		return (head);
	}
	free(res);
	free_array(split);
	return (NULL);
}

void	free_list(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
