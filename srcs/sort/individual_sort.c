/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   individual_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:45:38 by albernar          #+#    #+#             */
/*   Updated: 2024/10/16 20:45:38 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_best_path(t_stack *stack_a, t_stack *stack_b,
		size_t best_scorer_index, size_t match_index)
{
	size_t	best_path;

	best_path = get_score_path(best_scorer_index, match_index, stack_a,
			stack_b);
	while (best_scorer_index != 0 && match_index != 0)
	{
		if (best_scorer_index == stack_a->size || match_index == stack_b->size)
			break ;
		else if (best_path == REVROTATE)
		{
			revrotate_r(stack_a, stack_b);
			best_scorer_index++;
			match_index++;
		}
		else if (best_path == ROTATE)
		{
			rotate_r(stack_a, stack_b);
			best_scorer_index--;
			match_index--;
		}
	}
}

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
