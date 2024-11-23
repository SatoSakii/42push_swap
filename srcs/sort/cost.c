/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:49:06 by albernar          #+#    #+#             */
/*   Updated: 2024/11/23 02:49:24 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_target_position(t_stack *stack, int num)
{
	size_t	i;

	i = 0;
	if (stack->size == 0)
		return (0);
	if (num > stack->tab[get_maxindex(stack)])
		return (0);
	if (num < stack->tab[get_minindex(stack)])
		return (get_maxindex(stack));
	while (i < stack->size - 1)
	{
		if (num < stack->tab[i] && num > stack->tab[i + 1])
			return (i + 1);
		i++;
	}
	if (num < stack->tab[stack->size - 1] && num > stack->tab[0])
		return (0);
	return (i);
}

size_t	calculate_cost(t_stack *stack_a, t_stack *stack_b, int num)
{
	size_t	pos_a;
	size_t	pos_b;
	size_t	cost;

	pos_a = 0;
	cost = 0;
	while (pos_a < stack_a->size && stack_a->tab[pos_a] != num)
		pos_a++;
	pos_b = find_target_position(stack_b, num);
	if (pos_a > stack_a->size / 2)
		cost += stack_a->size - pos_a;
	else
		cost += pos_a;
	if (pos_b > stack_b->size / 2)
		cost += stack_b->size - pos_b;
	else
		cost += pos_b;
	return (cost + 1);
}

size_t	find_cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;
	size_t	cheapest_pos;
	size_t	min_cost;
	size_t	current_cost;

	i = 0;
	cheapest_pos = 0;
	min_cost = (size_t)(-1);
	while (i < stack_a->size)
	{
		current_cost = calculate_cost(stack_a, stack_b, stack_a->tab[i]);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest_pos = i;
		}
		i++;
	}
	return (cheapest_pos);
}
