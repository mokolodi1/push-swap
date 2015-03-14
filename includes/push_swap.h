/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 19:00:08 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/14 19:35:03 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** authorized functions:
** write
** malloc
** free
** exit
*/

# include "libft.h"
# include "ft_printf.h"
# include <limits.h>

# define PATH_FINDING_MAX_LENGTH		6

typedef enum			e_operator
{
	NO_OPERATOR
	, SWAP_A, SWAP_B, SWAP_BOTH
	, PUSH_A, PUSH_B
	, ROTATE_A, ROTATE_B, ROTATE_A_B
	, REVERSE_ROTATE_A, REVERSE_ROTATE_B, REVERSE_ROTATE_A_B
}						t_operator;

void					handle_push_swap(int length, int *numbers);
int						check_for_exception(int length, int *numbers
											, t_operator **solution
											, int *solution_length);
void					print_operators(int length, t_operator *operators);

/*
** path finding solution: finds optimal solution using a priority
** queue and a heuristic.
*/

/*
** first/second[*_length] = number of other uses (other than original)
*/

typedef struct			s_try
{
	int					*first;
	int					*second;
	int					first_length;
	int					second_length;
	t_operator			*operators;
	int					depth;
	int					sortedness;
	int					score;
}						t_try;

/*
** pq: priority queue for tries
** ascending_numbers: [0, 1, 2, ... length]
** solution: best solution so far
*/

typedef struct			s_search
{
	t_priority_queue	*pq;
	size_t				permutation_count;
	int					*ascending_numbers;
	t_operator			*solution;
	int					solution_length;
}						t_search;

void					path_finding_push_swap(int lenght, int *numbers
												, t_operator **solution
												, int *solution_length);
void					permutate(t_search *search);
void					found_solution(t_try *try, t_search *search);
void					add_swaps(t_try *old, t_search *search
												, t_operator last_operator);
void					add_pushes(t_try *old, t_search *search
												, t_operator last_operator);
void					add_rotates(t_try *old, t_search *search
												, t_operator last_operator);
void					add_reverse_rotates(t_try *old, t_search *search
												, t_operator last_operator);
int						compare_tries(t_try *first, t_try *second);
t_try					*create_general_try(t_try *old);
void					free_try(t_try *try);
void					set_score(t_try *try);

/*
** quicksort: not necessarily optimal solution, but sorts in N *
** log(N) time
*/

# define PARTITION_CUTOFF			3

typedef struct			s_entry
{
	int					number;
	struct s_entry		*previous;
	struct s_entry		*next;
}						t_entry;

typedef struct			s_solution
{
	t_operator			*operators;
	int					malloc_length;
	int					length;
}						t_solution;

typedef struct			s_stack
{
	t_entry				*first;
	t_solution			*solution;
	t_operator			swap_stack;
	t_operator			push_to_this_stack;
	t_operator			rotate_stack;
	t_operator			reverse_rotate_stack;
}						t_stack;

void					quicksort_push_swap(int length, int *numbers
											, t_operator **overall_solution
											, int *solution_length);
void					partition_to_cutoff(t_stack *destination
											, t_stack *source
											, int source_length);
int						get_pivot(t_entry *entries, int length);
void					cutoff_reached(t_stack *second, t_stack *first
											, int length);
void					add_to_solution(t_solution *solution
											, t_operator operator);

void					convert_entries_to_array(t_entry *entries, int length
											, int *numbers);
t_entry					*get_nth_entry(t_entry *first, int n);

/*
** located in stack_operations.c
*/

void					swap(t_stack *destination, t_stack *source);
void					push(t_stack *destination, t_stack *source);
void					rotate(t_stack *destination, t_stack *source);
void					reverse_rotate(t_stack *destination, t_stack *source);

#endif
