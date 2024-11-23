/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:50:19 by albernar          #+#    #+#             */
/*   Updated: 2024/11/23 02:27:32 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_highest_target_index(t_stack *stack, int target)
{
	size_t	index;
	size_t	index_best_value;
	ssize_t	best_value;

	index_best_value = 0;
	best_value = 2147483647;
	index = 0;
	while (index < stack->size)
	{
		if (stack->tab[index] > target && stack->tab[index] < best_value)
		{
			best_value = stack->tab[index];
			index_best_value = index;
		}
		index++;
	}
	if (best_value == 2147483647)
		return (get_minindex(stack));
	return (index_best_value);
}

size_t	find_lowest_target_index(t_stack *stack, int target)
{
	size_t	index;
	size_t	index_best_value;
	ssize_t	best_value;

	index_best_value = 0;
	best_value = -2147483648;
	index = 0;
	while (index < stack->size)
	{
		if (stack->tab[index] < target && stack->tab[index] > best_value)
		{
			best_value = stack->tab[index];
			index_best_value = index;
		}
		index++;
	}
	if (best_value == -2147483648)
		return (get_maxindex(stack));
	return (index_best_value);
}

int	get_minindex(t_stack *stack)
{
	size_t	tmp;
	size_t	i;

	i = 0;
	tmp = 0;
	if (!stack->size)
		return (-1);
	while (i < stack->size)
	{
		if (*(stack->tab + i) < *(stack->tab + tmp))
			tmp = i;
		i++;
	}
	return (tmp);
}

int	get_maxindex(t_stack *stack)
{
	size_t	tmp;
	size_t	i;

	i = 0;
	tmp = 0;
	if (!stack->size)
		return (-1);
	while (i < stack->size)
	{
		if (*(stack->tab + i) > *(stack->tab + tmp))
			tmp = i;
		i++;
	}
	return (tmp);
}

int	is_sorted(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (*(stack->tab + i) > *(stack->tab + i + 1))
			return (0);
		i++;
	}
	return (1);
}
