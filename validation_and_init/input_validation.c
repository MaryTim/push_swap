/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:50:03 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/08/21 15:50:40 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*make_int_array(int argc, char **argv, int i)
{
	int		*res;
	int		j;
	long	nbr;

	j = 0;
	res = malloc(sizeof(int) * (argc - 1));
	if (!res)
		return (NULL);
	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		if (!check_min_max_int(nbr))
		{
			free(res);
			return (NULL);
		}
		res[j] = (int)nbr;
		i++;
		j++;
	}
	return (res);
}

int	*int_array_from_string(char	**split_res)
{
	int		*res;
	int		j;
	int		k;
	long	nbr;

	j = 0;
	k = 0;
	res = malloc(sizeof(int) * count_elements(split_res));
	if (!res)
		return (NULL);
	while (split_res[j])
	{
		nbr = ft_atol(split_res[j]);
		if (!check_min_max_int(nbr))
		{
			free(res);
			return (NULL);
		}
		res[j] = (int)nbr;
		j++;
		k++;
	}
	return (res);
}

bool	has_duplicates(int *array, int size)
{
	int	j;
	int	k;

	j = 0;
	while (j < size - 1)
	{
		k = j + 1;
		while (k < size)
		{
			if (array[j] == array[k])
			{
				print_error_message("Please make sure your input ",
					"doesn't contain duplicates!");
				return (true);
			}
			k++;
		}
		j++;
	}
	return (false);
}

int	*handle_two_args(char **argv)
{
	int		*res;
	char	**split_res;

	split_res = ft_split(argv[1], ' ');
	if (split_res[0] == NULL)
		print_error_message("Please check your input params!", "");
	if (only_numbers(split_res, 0) == true)
	{
		res = int_array_from_string(split_res);
		if (res && !has_duplicates(res, count_elements(split_res)))
		{
			free_array(split_res);
			return (res);
		}
		free(res);
		free_array(split_res);
		return (NULL);
	}
	free_array(split_res);
	return (NULL);
}

int	*validation_and_result(int argc, char **argv)
{
	int		*res;

	if (argc == 2)
		return (handle_two_args(argv));
	if (only_numbers(argv, 1))
	{
		res = make_int_array(argc, argv, 1);
		if (res && !has_duplicates(res, argc -1))
			return (res);
		else
		{
			free(res);
			return (NULL);
		}
	}
	return (NULL);
}
