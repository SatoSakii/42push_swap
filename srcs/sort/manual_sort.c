/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:50:04 by albernar          #+#    #+#             */
/*   Updated: 2024/11/22 06:59:15 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (is_sorted(stack))
		return ;
	swap_a(stack);
}

void	sort_three(t_stack *stack)
{
	int	min;
	int	max;

	if (is_sorted(stack))
		return ;
	min = get_minindex(stack);
	max = get_maxindex(stack);
	if (min == 0 || (min == 1 && max == 2) || (min == 2 && max == 0))
		swap_a(stack);
	if (min == 0 || (min == 1 && max == 0))
		rotate_a(stack);
	if ((min == 2 && max == 1) || (min == 2 && max == 0))
		revrotate_a(stack);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;

	if (is_sorted(stack_a))
		return ;
	min_index = get_minindex(stack_a);
	if (min_index == 1)
		rotate_a(stack_a);
	else if (min_index == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (min_index == 3)
		revrotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;

	if (is_sorted(stack_a))
		return ;
	min_index = get_minindex(stack_a);
	if (min_index == 1)
		rotate_a(stack_a);
	else if (min_index == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (min_index == 3)
	{
		revrotate_a(stack_a);
		revrotate_a(stack_a);
	}
	else if (min_index == 4)
		revrotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	manual_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	else if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else
		return ;
}
