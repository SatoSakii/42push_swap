/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   individual_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:45:38 by albernar          #+#    #+#             */
/*   Updated: 2024/10/16 20:45:38 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (is_sorted(stack))
		return ;
	swap_a(stack);
}

void	sort_three(t_stack *stack)
{
	int	min;
	int	max;

	if (is_sorted(stack))
		return ;
	min = get_minindex(stack);
	max = get_maxindex(stack);
	if (min == 0 || (min == 1 && max == 2) || (min == 2 && max == 0))
		swap_a(stack);
	if (min == 0 || (min == 1 && max == 0))
		rotate_a(stack);
	if ((min == 2 && max == 1) || (min == 2 && max == 0))
		revrotate_a(stack);
}
