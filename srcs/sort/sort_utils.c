/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 05:38:13 by albernar          #+#    #+#             */
/*   Updated: 2024/10/13 05:38:23 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_max(size_t a, size_t b)
{
	if (a < b)
		return (b);
	return (a);
}

size_t	get_diff(int a, int b)
{
	if (a < b)
		return (b - a);
	return (a - b);
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
		if (*(stack->stack + i) < *(stack->stack + tmp))
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
	while (i < stack->size)
	{
		if (*(stack->stack + i) > *(stack->stack + tmp))
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
		if (*(stack->stack + i) > *(stack->stack + i + 1))
			return (0);
		i++;
	}
	return (1);
}
