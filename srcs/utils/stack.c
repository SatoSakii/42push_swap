/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <albernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 01:27:46 by albernar          #+#    #+#             */
/*   Updated: 2024/10/16 19:59:40 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(int *arr, int size, t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		stack_a->stack = arr;
		stack_a->size = size;
	}
	if (stack_b)
	{
		stack_b->size = 0;
		stack_b->stack = ft_calloc(size, sizeof(int));
		if (!stack_b->stack)
			return ;
	}
}
