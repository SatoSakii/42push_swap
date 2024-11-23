/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:13:15 by albernar          #+#    #+#             */
/*   Updated: 2024/11/23 02:08:48 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	size_t	i;

	if (!src->size)
		return ;
	i = dst->size;
	while (i > 0)
	{
		dst->tab[i] = dst->tab[i - 1];
		i--;
	}
	dst->tab[0] = src->tab[0];
	dst->size++;
	i = 0;
	while (i < src->size - 1)
	{
		src->tab[i] = src->tab[i + 1];
		i++;
	}
	src->size--;
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
