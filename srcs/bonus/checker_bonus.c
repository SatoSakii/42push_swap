/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 08:33:07 by albernar          #+#    #+#             */
/*   Updated: 2024/11/23 19:41:05 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	checker_start(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_line(line))
		{
			free(line);
			free(stack_a->tab);
			free(stack_b->tab);
			get_next_line(-1);
			error_message();
		}
		exec_push(line, stack_a, stack_b);
		exec_revrotate(line, stack_a, stack_b);
		exec_rotate(line, stack_a, stack_b);
		exec_swap(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	get_next_line(-1);
}
