/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 19:00:08 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/07 18:31:06 by tfleming         ###   ########.fr       */
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
# include <limits.h>
# include <stdio.h> // nope

# define PATH_FINDING_MAX_LENGTH		6

/*
** path finding solution: finds optimal solution using a priority
** queue and a heuristic.
*/

typedef enum			e_operator
{
	NO_OPERATOR
	, SWAP_A, SWAP_B, SWAP_S
	, PUSH_A, PUSH_B
	, ROTATE_A, ROTATE_B, ROTATE_A_B
	, REVERSE_ROTATE_A, REVERSE_ROTATE_B, REVERSE_ROTATE_A_B
}						t_operator;

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
	int					refining_answer;
}						t_search;

void					path_finding_push_swap(int lenght, int *numbers
											, int refining_answer);
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
void					print_operators(int length, t_operator *operators);

/*
** quicksort: not necessarily optimal solution, but sorts in N *
** log(N) time
*/

# define STARTING_SOLUTION_LENGTH	10
# define PARTITION_CUTOFF			3

typedef struct			s_entry
{
	int					number;
	struct s_entry		*last;
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
	t_entry				*entries;
	t_solution			*solution;
	t_operator			push_to_this_operator;
	t_operator			rotate_this_operator;
}						t_stack;

void					quicksort_push_swap(int length, int *numbers);
void					partition_to_cutoff(t_stack *first, t_stack *second
											, int first_length
											, int second_length);
void					add_to_solution(t_solution *solution
											, t_operator operator);
void					clean_solution(int length, t_operator **operators);

#endif
