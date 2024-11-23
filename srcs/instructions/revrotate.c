/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:11:56 by albernar          #+#    #+#             */
/*   Updated: 2024/11/23 02:08:50 by albernar         ###   ########.fr       */
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
	last = stack->tab[stack->size - 1];
	while (i > 0)
	{
		*(stack->tab + i) = *(stack->tab + i - 1);
		i--;
	}
	*stack->tab = last;
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
