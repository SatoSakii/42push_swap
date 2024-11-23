/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:24:21 by albernar          #+#    #+#             */
/*   Updated: 2024/11/22 05:46:04 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2dptr(void **ptr)
{
	void	**tmp_ptr;

	tmp_ptr = ptr;
	while (*ptr)
		free(*ptr++);
	free(tmp_ptr);
}

int	is_number(const char *str)
{
	if (!str || !*str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (*str && ft_isdigit(*str))
		str++;
	return (*str == 0);
}
