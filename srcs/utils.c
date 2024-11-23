/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 08:11:30 by albernar          #+#    #+#             */
/*   Updated: 2024/11/23 19:40:58 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(void)
{
	write(2, ERROR_MESS, ft_strlen(ERROR_MESS));
	exit (1);
}

void	init_stack(int *tab, int size, t_stack *stack_a, t_stack *stack_b)
{
	stack_a->tab = tab;
	stack_a->size = size;
	stack_b->tab = malloc(sizeof(int) * size);
	if (!stack_b->tab)
	{
		free(tab);
		error_message();
	}
	stack_b->size = 0;
}
