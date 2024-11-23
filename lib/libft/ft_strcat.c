/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:14:37 by albernar          #+#    #+#             */
/*   Updated: 2024/11/21 21:14:49 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, char *src)
{
	char	*tmp_dst;

	tmp_dst = dst;
	while (*tmp_dst)
		tmp_dst++;
	while (*src)
		*tmp_dst++ = *src++;
	*tmp_dst = 0;
	return (dst);
}