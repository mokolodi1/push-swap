/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 19:00:08 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/15 00:57:27 by tfleming         ###   ########.fr       */
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

# define DEPTH_MULTIPLIER	2

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
}						t_search;

void					handle_push_swap(int lenght, int *numbers);
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


void					print_try(t_try *try);

/*
** todo: something to clean up the priorityqueue when we find a
** shorter solution
**
** todo: what to do when there are too many tries on the priority
** queue (too much memory much?)
*/

#endif
