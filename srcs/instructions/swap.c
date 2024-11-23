/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:13:57 by albernar          #+#    #+#             */
/*   Updated: 2024/11/22 06:14:57 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size <= 1)
		return ;
	tmp = *stack->tab;
	*stack->tab = *(stack->tab + 1);
	*(stack->tab + 1) = tmp;
}

void	swap_a(t_stack *stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	swap_s(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
