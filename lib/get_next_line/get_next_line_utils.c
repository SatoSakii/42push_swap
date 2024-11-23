/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 08:35:15 by albernar          #+#    #+#             */
/*   Updated: 2024/11/22 08:38:46 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = s;
	while (n--)
		*tmp++ = (unsigned char)c;
	return (s);
}

void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*ptr;

	if (nmenb && (nmenb * size) / nmenb != size)
		return (NULL);
	ptr = malloc(nmenb * size);
	if (!ptr)
		return (NULL);
	if (size == 0)
		return (ptr);
	ft_memset(ptr, 0, nmenb * size);
	return (ptr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	if (!src)
		return (size);
	if (!dst)
		return (size + ft_strlen(src));
	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (size <= dest_len)
		return (size + src_len);
	dst += dest_len;
	while (*src && (dest_len + i++) < (size - 1))
		*dst++ = *src++;
	*dst = 0;
	return (src_len + dest_len);
}

char	*ft_strjoin(char const *s1, char const *s2, int free_s1, int free_s2)
{
	char	*dest;

	free_s1 = !!s1 * free_s1;
	free_s2 = !!s2 * free_s2;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	dest = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	ft_strlcat(dest, s1, ft_strlen(s1) + 1);
	ft_strlcat(dest, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (free_s1)
		free((char *)s1);
	if (free_s2)
		free((char *)s2);
	return (dest);
}
