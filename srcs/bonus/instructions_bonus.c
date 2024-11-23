/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 08:32:42 by albernar          #+#    #+#             */
/*   Updated: 2024/11/22 09:05:11 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	exec_push(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(str, "pa\n") == 0)
		push(stack_b, stack_a);
	if (ft_strcmp(str, "pb\n") == 0)
		push(stack_a, stack_b);
}

void	exec_revrotate(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(str, "rra\n") == 0)
		revrotate(stack_a);
	if (ft_strcmp(str, "rrb\n") == 0)
		revrotate(stack_b);
	if (ft_strcmp(str, "rrr\n") == 0)
	{
		revrotate(stack_a);
		revrotate(stack_b);
	}
}

void	exec_rotate(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(str, "ra\n") == 0)
		rotate(stack_a);
	if (ft_strcmp(str, "rb\n") == 0)
		rotate(stack_b);
	if (ft_strcmp(str, "rr\n") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}

void	exec_swap(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		swap(stack_a);
	if (ft_strcmp(str, "sb\n") == 0)
		swap(stack_b);
	if (ft_strcmp(str, "ss\n") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
}
