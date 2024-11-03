/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_score_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:47:44 by albernar          #+#    #+#             */
/*   Updated: 2024/11/03 18:26:01 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_highest_relative_index(t_stack *stack, int target)
{
	size_t	match_index;
	size_t	current_diff;
	size_t	lowest_diff;
	size_t	i;

	i = 0;
	lowest_diff = 4294967295;
	match_index = 4294967295;
	while (i < stack->size)
	{
		if (stack->stack[i] > target)
		{
			current_diff = get_diff(stack->stack[i], target);
			if (lowest_diff > current_diff)
			{
				lowest_diff = current_diff;
				match_index = i;
			}
		}
		i++;
	}
	if (match_index == 4294967295)
		return (get_minindex(stack));
	return (match_index);
}

size_t	find_lowest_relative_index(t_stack *stack, int target)
{
	size_t	match_index;
	size_t	current_diff;
	size_t	lowest_diff;
	size_t	i;

	i = 0;
	lowest_diff = 4294967295;
	match_index = 4294967295;
	while (i < stack->size)
	{
		if (stack->stack[i] < target)
		{
			current_diff = get_diff(stack->stack[i], target);
			if (lowest_diff > current_diff)
			{
				lowest_diff = current_diff;
				match_index = i;
			}
		}
		i++;
	}
	if (match_index == 4294967295)
		return (get_maxindex(stack));
	return (match_index);
}

size_t	get_score_path(size_t target_index, size_t match_index,
		t_stack *stack_a, t_stack *stack_b)
{
	size_t	rotate_score;
	size_t	revrotate_score;

	rotate_score = get_max(target_index, match_index);
	revrotate_score = get_max(stack_a->size - target_index, stack_b->size
			- match_index);
	if (rotate_score <= revrotate_score)
		return (ROTATE);
	else
		return (REVROTATE);
}

size_t	calculate_score(size_t target_index, size_t match_index,
		t_stack *stack_a, t_stack *stack_b)
{
	size_t	rotate_score;
	size_t	revrotate_score;
	size_t	cross_score_1;
	size_t	cross_score_2;
	size_t	best_score;

	rotate_score = get_max(target_index, match_index);
	revrotate_score = get_max(stack_a->size - target_index, stack_b->size
			- match_index);
	cross_score_1 = target_index + (stack_b->size - match_index);
	cross_score_2 = (stack_a->size - target_index) + match_index;
	best_score = rotate_score;
	if (revrotate_score < best_score)
		best_score = revrotate_score;
	if (cross_score_1 < best_score)
		best_score = cross_score_1;
	if (cross_score_2 < best_score)
		best_score = cross_score_2;
	return (best_score);
}

size_t	find_best_scorer(t_stack *stack_a, t_stack *stack_b)
{
	size_t	best_score;
	size_t	best_scorer_index;
	size_t	i;
	size_t	match_index;
	size_t	score;

	best_score = 4294967295;
	best_scorer_index = 0;
	i = 0;
	while (i < stack_a->size)
	{
		match_index = find_lowest_relative_index(stack_b, stack_a->stack[i]);
		score = calculate_score(i, match_index, stack_a, stack_b);
		if (score < best_score)
		{
			best_score = score;
			best_scorer_index = i;
		}
		i++;
	}
	return (best_scorer_index);
}
