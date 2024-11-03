/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:34:25 by albernar          #+#    #+#             */
/*   Updated: 2024/10/13 01:45:05 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*nums;
	int		size;
	t_stack	stack_a;
	t_stack	stack_b;

	nums = check_args(argc, argv, &size);
	if (!nums)
		return (ft_error());
	init_stack(nums, size - 1, &stack_a, &stack_b);
	turkish_sort(&stack_a, &stack_b);
	free(nums);
	free(stack_b.stack);
}
