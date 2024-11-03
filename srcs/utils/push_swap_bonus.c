/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 08:54:44 by albernar          #+#    #+#             */
/*   Updated: 2024/10/13 09:04:45 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	check_line(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "sa\n") == 0
		|| ft_strcmp(str, "ss\n") == 0 || ft_strcmp(str, "pa\n") == 0
		|| ft_strcmp(str, "pb\n") == 0 || ft_strcmp(str, "ra\n") == 0
		|| ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rb\n") == 0
		|| ft_strcmp(str, "rr\n") == 0 || ft_strcmp(str, "rra\n") == 0
		|| ft_strcmp(str, "rrb\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		return (1);
	return (0);
}

void	exec_instructions_sp(char *str, t_stack *stack_a, t_stack *stack_b)
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
	if (ft_strcmp(str, "pa\n") == 0)
		push(stack_b, stack_a);
	if (ft_strcmp(str, "pb\n") == 0)
		push(stack_a, stack_b);
}

void	exec_instructions_r(char *str, t_stack *stack_a, t_stack *stack_b)
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

void	read_stdin(t_stack *stack_a, t_stack *stack_b, int *nums)
{
	int		failed;
	char	*line;

	line = get_next_line(0);
	failed = 0;
	while (line)
	{
		if (!failed && !check_line(line))
			failed = 1;
		exec_instructions_sp(line, stack_a, stack_b);
		exec_instructions_r(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (failed)
	{
		free(stack_b->stack);
		free(nums);
		exit(ft_error());
	}
}
