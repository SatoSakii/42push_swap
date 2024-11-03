/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 01:07:37 by albernar          #+#    #+#             */
/*   Updated: 2024/10/11 07:50:37 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp_dest;
	char	*dest;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (!len)
		start = 0;
	if (ft_strlen(s) < len + start)
		len = ft_strlen(s + start);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	s += start;
	tmp_dest = dest;
	while (*s && len--)
		*tmp_dest++ = *s++;
	*tmp_dest = 0;
	return (dest);
}

static char	*ft_find_sep(char *str, char sep)
{
	while (*str && *str != sep)
		str++;
	return (str);
}

static int	find_words(char *str, char charset, char **saveptr)
{
	char	*start;
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && charset && ft_find_sep(str, charset) == str)
			str++;
		count += (*str != 0);
		start = str;
		str = ft_find_sep(start, charset);
		if (!saveptr || !(*start))
			continue ;
		*(saveptr + count - 1) = ft_substr(start, 0, str - start);
		if (!*(saveptr + count - 1))
			break ;
	}
	return (count);
}

void	free_split(char **strs)
{
	char	**start;

	start = strs;
	while (*strs)
		free(*strs++);
	free(start);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;

	if (!s)
		return (NULL);
	size = find_words((char *)s, c, 0);
	result = malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	*(result + size) = 0;
	if (find_words((char *)s, c, result) == size)
		return (result);
	free_split(result);
	return (NULL);
}
