/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:47:56 by albernar          #+#    #+#             */
/*   Updated: 2024/11/23 02:48:18 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_element_to_top(t_stack *stack, size_t *index, int stack_type)
{
	while (*index != 0)
	{
		if (*index == stack->size)
			(*index) = 0;
		else if (*index <= stack->size / 2)
		{
			if (stack_type == 1)
				rotate_a(stack);
			else if (stack_type == 2)
				rotate_b(stack);
			(*index)--;
		}
		else
		{
			if (stack_type == 1)
				revrotate_a(stack);
			else if (stack_type == 2)
				revrotate_b(stack);
			(*index)++;
		}
	}
}

void	synchronize_rotations(t_stack *stack_a, t_stack *stack_b,
		size_t *index_a, size_t *index_b)
{
	while (*index_a > 0 && *index_b > 0 && *index_a <= stack_a->size / 2
		&& *index_b <= stack_b->size / 2)
	{
		rotate_r(stack_a, stack_b);
		(*index_a)--;
		(*index_b)--;
	}
	while (*index_a < stack_a->size && *index_b < stack_b->size
		&& *index_a > stack_a->size / 2 && *index_b > stack_b->size / 2)
	{
		revrotate_r(stack_a, stack_b);
		(*index_a)++;
		(*index_b)++;
	}
	move_element_to_top(stack_a, index_a, 1);
	move_element_to_top(stack_b, index_b, 2);
}
