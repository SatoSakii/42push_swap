/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:52:34 by albernar          #+#    #+#             */
/*   Updated: 2024/10/13 08:26:03 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	const char	*tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	return (tmp - s);
}

int	ft_atoi(const char *str, int *ptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str != '\0' && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str != '\0' && (!(*str < '0' || *str > '9')))
		result = result * 10 + *str++ - '0';
	result *= sign;
	if ((result > 0 && sign == -1) || (result < 0 && sign == 1))
		return (1);
	*ptr = result;
	return (0);
}

int	isnum(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str && (*str >= '0' && *str <= '9'))
		str++;
	if (!*str)
		return (1);
	return (0);
}

void	*ft_calloc(size_t nmenb, size_t size)
{
	unsigned char	*tmp;
	size_t			n;
	void			*ptr;

	if (nmenb && (nmenb * size) / nmenb != size)
		return (NULL);
	ptr = malloc(nmenb * size);
	if (!ptr)
		return (NULL);
	if (size == 0)
		return (ptr);
	tmp = ptr;
	n = nmenb * size;
	while (n--)
		*tmp++ = 0;
	return (ptr);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
