/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:58:17 by albernar          #+#    #+#             */
/*   Updated: 2024/10/12 23:58:23 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_secure_args(char **split_strs, int *nums)
{
	if (split_strs)
		free_split(split_strs);
	if (nums)
		free(nums);
	return (NULL);
}

int	free_secure_args2(char **split_strs)
{
	if (split_strs)
		free_split(split_strs);
	return (-1);
}

int	count_total_args(int argc, char **argv)
{
	char		**strs;
	char		**tmp_strs;
	static int	count;

	count = 1;
	while (argc-- != 1)
	{
		strs = ft_split(*argv, ' ');
		if (!*strs)
			return (free_secure_args2(strs));
		tmp_strs = strs;
		while (*strs)
		{
			if (!isnum(*strs))
			{
				free_split(tmp_strs);
				return (-1);
			}
			strs++;
			count++;
		}
		free_split(tmp_strs);
		argv++;
	}
	return (count);
}

int	*fill_total_args(int argc, char **argv, int size)
{
	int		i;
	int		*nums;
	char	**strs;
	char	**tmp_strs;

	i = 0;
	nums = malloc(sizeof(int) * size);
	if (!nums)
		return (NULL);
	while (argc-- != 1)
	{
		strs = ft_split(*argv, ' ');
		tmp_strs = strs;
		while (*strs)
		{
			if (!isnum(*strs))
				return (free_secure_args(tmp_strs, NULL));
			if (ft_atoi(*strs, (nums + i++)))
				return (free_secure_args(tmp_strs, nums));
			strs++;
		}
		free_split(tmp_strs);
		argv++;
	}
	return (nums);
}
