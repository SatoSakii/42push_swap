/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 01:12:49 by albernar          #+#    #+#             */
/*   Updated: 2024/10/13 01:39:19 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate(t_stack *stack)
{
	size_t	i;
	int		last;

	if (stack->size < 2)
		return ;
	i = stack->size - 1;
	last = stack->stack[stack->size - 1];
	while (i > 0)
	{
		*(stack->stack + i) = *(stack->stack + i - 1);
		i--;
	}
	*stack->stack = last;
}

void	revrotate_a(t_stack *stack_a)
{
	revrotate(stack_a);
	write(1, "rra\n", 4);
}

void	revrotate_b(t_stack *stack_b)
{
	revrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	revrotate_r(t_stack *stack_a, t_stack *stack_b)
{
	revrotate(stack_a);
	revrotate(stack_b);
	write(1, "rrr\n", 4);
}
