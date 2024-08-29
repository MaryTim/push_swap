/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:07:41 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/08/21 11:10:59 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	list_size(t_node *my_node)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = my_node;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
