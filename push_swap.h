/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:43:45 by albernar          #+#    #+#             */
/*   Updated: 2024/10/13 01:21:15 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// LIST
typedef struct s_stack
{
	int		*stack;
	size_t	size;
}	t_stack;

typedef enum e_stack_path
{
	ROTATE,
	REVROTATE,
	CONFLICT_ROTATE
}	t_stack_path;

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

// UTILS FUNCTIONS
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str, int *ptr);
int		isnum(char *str);
int		has_dupes(int *arr, int size);
int		count_total_args(int argc, char **argv);
int		*fill_total_args(int argc, char **argv, int size);
int		*check_args(int argc, char **argv, int *size);
int		ft_error(void);
void	init_stack(int *arr, int size, t_stack *stack_a, t_stack *stack_b);
void	*ft_calloc(size_t nmenb, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2, int free_s1, int free_s2);
void	free_split(char **strs);

// SORT UTILS FUNCTIONS
size_t	calculate_score(size_t target_index, size_t match_index,
		t_stack *stack_a, t_stack *stack_b);
size_t	get_score_path(size_t target_index, size_t match_index,
		t_stack *stack_a, t_stack *stack_b);
size_t	find_lowest_relative_index(t_stack *stack, int target);
size_t	find_highest_relative_index(t_stack *stack, int target);
size_t	get_max(size_t a, size_t b);
size_t	get_diff(int a, int b);
size_t	find_best_scorer(t_stack *stack_a, t_stack *stack_b);
int		get_minindex(t_stack *stack);
int		get_maxindex(t_stack *stack);
int		is_sorted(t_stack *stack);

// SORT FUNCTIONS
void	turkish_sort(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	sort_two(t_stack *stack_a);

// BONUS FUNCTIONS
char	*get_next_line(int fd);
int		check_line(char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	exec_instructions_sp(char *str, t_stack *stack_a, t_stack *stack_b);
void	exec_instructions_r(char *str, t_stack *stack_a, t_stack *stack_b);
void	read_stdin(t_stack *stack_a, t_stack *stack_b, int *nums);

#endif
