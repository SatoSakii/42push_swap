/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 08:13:27 by albernar          #+#    #+#             */
/*   Updated: 2024/10/13 08:54:22 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*nums;
	int		size;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (1);
	nums = check_args(argc, argv, &size);
	if (!nums)
		return (ft_error());
	init_stack(nums, size - 1, &stack_a, &stack_b);
	read_stdin(&stack_a, &stack_b, nums);
	if (is_sorted(&stack_a) && stack_b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_b.stack);
	free(nums);
	return (0);
}
