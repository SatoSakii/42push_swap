/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 05:39:49 by albernar          #+#    #+#             */
/*   Updated: 2024/11/03 18:26:19 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_elements_to_top(t_stack *stack, int stack_type, size_t index)
{
	while (index != 0)
	{
		if (index == stack->size)
			index = 0;
		else if (index <= stack->size / 2)
		{
			if (stack_type == 1)
				rotate_a(stack);
			else if (stack_type == 0)
				rotate_b(stack);
			index--;
		}
		else
		{
			if (stack_type == 1)
				revrotate_a(stack);
			else if (stack_type == 0)
				revrotate_b(stack);
			index++;
		}
	}
}

void	sort_b_to_push(t_stack *stack_a, t_stack *stack_b)
{
	size_t	match_index;

	match_index = find_highest_relative_index(stack_a, stack_b->stack[0]);
	move_elements_to_top(stack_a, 1, match_index);
	push_a(stack_a, stack_b);
}

void	finish_sort(t_stack *stack_a)
{
	size_t	min_index;

	min_index = get_minindex(stack_a);
	if (min_index <= stack_a->size / 2)
	{
		while (min_index-- > 0)
			rotate_a(stack_a);
	}
	else
	{
		while (min_index++ < stack_a->size)
			revrotate_a(stack_a);
	}
}

void	start_sort(t_stack *stack_a, t_stack *stack_b)
{
	size_t	best_scorer_index;
	size_t	match_index;

	best_scorer_index = find_best_scorer(stack_a, stack_b);
	match_index = find_lowest_relative_index(stack_b,
			stack_a->stack[best_scorer_index]);
	execute_best_path(stack_a, stack_b, best_scorer_index, match_index);
	move_elements_to_top(stack_b, 0, match_index);
	move_elements_to_top(stack_a, 1, best_scorer_index);
	push_b(stack_a, stack_b);
}

void	turkish_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (is_sorted(stack_a))
		return ;
	if (!is_sorted(stack_a) && stack_a->size == 2)
		return (sort_two(stack_a));
	if (!is_sorted(stack_a) && stack_a->size == 3)
		return (sort_three(stack_a));
	i = 0;
	while (i < 2 && stack_a->size > 3)
	{
		push_b(stack_a, stack_b);
		i++;
	}
	while (stack_a->size > 3)
		start_sort(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->size > 0)
		sort_b_to_push(stack_a, stack_b);
	finish_sort(stack_a);
}
