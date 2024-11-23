/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:13:00 by albernar          #+#    #+#             */
/*   Updated: 2024/11/23 02:08:52 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	size_t	i;
	int		first;

	if (stack->size < 2)
		return ;
	first = *stack->tab;
	i = 0;
	while (i < stack->size - 1)
	{
		*(stack->tab + i) = *(stack->tab + i + 1);
		i++;
	}
	*(stack->tab + stack->size - 1) = first;
}

void	rotate_a(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
