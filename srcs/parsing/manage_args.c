/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:11:55 by albernar          #+#    #+#             */
/*   Updated: 2024/11/23 19:41:15 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_dupes(int *arr, int size)
{
	int	*current;
	int	*tmp_arr;

	current = arr;
	while (current < arr + size - 1)
	{
		tmp_arr = current + 1;
		while (tmp_arr < arr + size - 1)
		{
			if (*current == *tmp_arr)
				return (1);
			tmp_arr++;
		}
		current++;
	}
	return (0);
}

int	count_args(int argc, char **argv)
{
	char	**split_args;
	char	**tmp_split_args;
	int		count;

	count = 1;
	while (argc-- > 1)
	{
		split_args = ft_split(*argv, ' ');
		if (!split_args)
			error_message();
		tmp_split_args = split_args;
		while (*split_args)
		{
			if (!is_number(*split_args))
			{
				free_2dptr((void **)tmp_split_args);
				error_message();
			}
			split_args++;
			count++;
		}
		free_2dptr((void **)tmp_split_args);
		argv++;
	}
	return (count);
}

void	add_tab_number(char *str, char **split_str, int *tab, int index)
{
	int	is_overflow;
	int	value;

	is_overflow = 0;
	value = ft_atoi(str, &is_overflow);
	if (is_overflow)
	{
		free_2dptr((void **)split_str);
		free(tab);
		error_message();
	}
	*(tab + index) = value;
}

int	*fill_args(int argc, char **argv, int size)
{
	int		*tab;
	char	**split_args;
	char	**tmp_split_args;
	int		i;

	i = -1;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		error_message();
	while (argc-- > 1)
	{
		split_args = ft_split(*argv, ' ');
		if (!split_args)
			error_message();
		tmp_split_args = split_args;
		while (*split_args)
		{
			add_tab_number(*split_args, tmp_split_args, tab, ++i);
			split_args++;
		}
		free_2dptr((void **)tmp_split_args);
		argv++;
	}
	return (tab);
}

int	*check_args(int argc, char **argv, int *_size)
{
	int	*tab;
	int	size;

	argv++;
	size = count_args(argc, argv);
	*_size = size;
	tab = fill_args(argc, argv, size);
	if (size == 1)
	{
		free(tab);
		error_message();
	}
	if (has_dupes(tab, size))
	{
		free(tab);
		error_message();
	}
	return (tab);
}
