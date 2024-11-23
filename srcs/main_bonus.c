/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 07:59:08 by albernar          #+#    #+#             */
/*   Updated: 2024/11/22 08:33:32 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	int		*tab;
	int		size;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc <= 1)
		error_message(NOT_ENOUGH_ARGS);
	tab = check_args(argc, argv, &size);
	init_stack(tab, size - 1, &stack_a, &stack_b);
	checker_start(&stack_a, &stack_b);
	if (is_sorted(&stack_a) && stack_b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_a.tab);
	free(stack_b.tab);
	return (0);
}
