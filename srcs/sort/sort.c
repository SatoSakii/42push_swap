/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:16:13 by albernar          #+#    #+#             */
/*   Updated: 2024/11/23 02:49:03 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	move_to_a(t_stack *stack_a, t_stack *stack_b)
{
	size_t	highest_target_index;
	size_t	index_b;

	highest_target_index = find_highest_target_index(stack_a, stack_b->tab[0]);
	index_b = 0;
	synchronize_rotations(stack_a, stack_b, &highest_target_index, &index_b);
	push_a(stack_a, stack_b);
}

void	move_to_b(t_stack *stack_a, t_stack *stack_b, size_t target_index)
{
	size_t	lowest_target_index;

	lowest_target_index = find_lowest_target_index(stack_b,
			stack_a->tab[target_index]);
	synchronize_rotations(stack_a, stack_b, &target_index,
		&lowest_target_index);
	push_b(stack_a, stack_b);
}

void	sort_tab(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	size_t	cheapest;
	size_t	max_index;
	size_t	min_index;

	i = 0;
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size <= 5)
		manual_sort(stack_a, stack_b);
	while (i++ < 2 && stack_a->size > 3)
		push_b(stack_a, stack_b);
	while (stack_a->size > 3)
	{
		cheapest = find_cheapest_move(stack_a, stack_b);
		move_to_b(stack_a, stack_b, cheapest);
	}
	max_index = get_maxindex(stack_b);
	move_element_to_top(stack_b, &max_index, 2);
	manual_sort(stack_a, stack_b);
	while (stack_b->size > 0)
		move_to_a(stack_a, stack_b);
	min_index = get_minindex(stack_a);
	move_element_to_top(stack_a, &min_index, 1);
}
