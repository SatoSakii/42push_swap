/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:00:28 by albernar          #+#    #+#             */
/*   Updated: 2024/11/23 02:46:43 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	sort_tab(&stack_a, &stack_b);
	free(stack_a.tab);
	free(stack_b.tab);
	return (0);
}
