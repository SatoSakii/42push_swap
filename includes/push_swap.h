/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 04:55:33 by albernar          #+#    #+#             */
/*   Updated: 2024/11/23 02:49:35 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESS				"Error\n"
# define MALLOC_FAILED 			"Malloc failed.\n"
# define NOT_ENOUGH_ARGS 		"Example : ./push_swap 1 9 0 -4 3\n"
# define ARGUMENTS_NOT_NUMBERS 	"Arguments are not only numbers.\n"
# define EXCEED_INT 			"Arguments exceed INT_MAX or INT_MIN.\n"
# define DUPES_NUMBERS			"Dupes are forbidden.\n"
# define EMPTY_ARGUMENTS		"Arguments are empty.\n"

typedef struct s_stack
{
	int		*tab;
	size_t	size;
}	t_stack;

typedef struct s_costs
{
	size_t	rra;
	size_t	ra;
	size_t	rrb;
	size_t	rb;
}	t_costs;

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

// SORT
void	sort_tab(t_stack *stack_a, t_stack *stack_b);

// MOVE STACK
void	move_element_to_top(t_stack *stack, size_t *index, int stack_type);
void	synchronize_rotations(t_stack *stack_a, t_stack *stack_b,
			size_t *index_a, size_t *index_b);

// COST UTILS
size_t	calculate_cost(t_stack *stack_a, t_stack *stack_b, int num);
size_t	find_cheapest_move(t_stack *stack_a, t_stack *stack_b);
size_t	find_target_position(t_stack *stack, int num);

// MANUAL SORT
void	manual_sort(t_stack *stack_a, t_stack *stack_b);

// SORT UTILS
size_t	find_highest_target_index(t_stack *stack, int target);
size_t	find_lowest_target_index(t_stack *stack, int target);
int		is_sorted(t_stack *stack);
int		get_minindex(t_stack *stack);
int		get_maxindex(t_stack *stack);

// BONUS
char	*get_next_line(int fd);

// UTILS
void	error_message(char *message);
void	init_stack(int *tab, int size, t_stack *stack_a, t_stack *stack_b);

#endif