/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 23:53:51 by albernar          #+#    #+#             */
/*   Updated: 2024/10/13 00:47:34 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_dupes(int *arr, int size)
{
	int	*current;
	int	*tmp_arr;

	current = arr;
	while (current < arr + size - 1)
	{
		tmp_arr = current + 1;
		while (tmp_arr < arr + size - 1)
		{
			if (*current == *tmp_arr)
				return (1);
			tmp_arr++;
		}
		current++;
	}
	return (0);
}

int	*check_args(int argc, char **argv, int *s)
{
	int	*nums;
	int	size;

	if (argc == 1)
		return (NULL);
	argv++;
	size = count_total_args(argc, argv);
	*s = size;
	if (size == -1 || size == 1)
		return (NULL);
	nums = fill_total_args(argc, argv, size);
	if (!nums)
		return (NULL);
	if (has_dupes(nums, size))
	{
		free(nums);
		return (NULL);
	}
	return (nums);
}
