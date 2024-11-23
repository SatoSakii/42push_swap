/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 04:55:33 by albernar          #+#    #+#             */
/*   Updated: 2024/11/22 09:09:27 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESS				"Error\n"
# define MALLOC_FAILED 			"Malloc failed.\n"
# define NOT_ENOUGH_ARGS 		"Example : ./checker 1 9 0 -4 3\n"
# define ARGUMENTS_NOT_NUMBERS 	"Arguments are not only numbers.\n"
# define EXCEED_INT 			"Arguments exceed INT_MAX or INT_MIN.\n"
# define DUPES_NUMBERS			"Dupes are forbidden.\n"
# define EMPTY_ARGUMENTS		"Arguments are empty.\n"
# define INVALID_CHECKER_MOVE	"Invalid instruction.\n"

typedef struct s_stack
{
	int		*tab;
	size_t	size;
}	t_stack;

// PARSING UTILS
void	free_2dptr(void **ptr);
int		is_number(const char *str);

// PARSING
int		*check_args(int argc, char **argv, int *_size);

// INSTRUCTIONS
void	swap(t_stack *stack);
void	push(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	revrotate(t_stack *stack);
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_s(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	rotate_a(t_stack *stack_a);
void	rotate_b(t_stack *stack_b);
void	rotate_r(t_stack *stack_a, t_stack *stack_b);
void	revrotate_a(t_stack *stack_a);
void	revrotate_b(t_stack *stack_b);
void	revrotate_r(t_stack *stack_a, t_stack *stack_b);

// SORT UTILS
int		is_sorted(t_stack *stack);
int		get_minindex(t_stack *stack);
int		get_maxindex(t_stack *stack);

// BONUS
char	*get_next_line(int fd);
void	checker_start(t_stack *stack_a, t_stack *stack_b);
void	exec_push(char *str, t_stack *stack_a, t_stack *stack_b);
void	exec_revrotate(char *str, t_stack *stack_a, t_stack *stack_b);
void	exec_rotate(char *str, t_stack *stack_a, t_stack *stack_b);
void	exec_swap(char *str, t_stack *stack_a, t_stack *stack_b);

// UTILS
void	error_message(char *message);
void	init_stack(int *tab, int size, t_stack *stack_a, t_stack *stack_b);

#endif