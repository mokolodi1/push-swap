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

typedef enum		e_operator
{
	SWAP_A, SWAP_B, SWAP_S
	, PUSH_A, PUSH_B
	, ROTATE_A, ROTATE_B, ROTATE_A_B
	, REVERSE_ROTATE_A, REVERSE_ROTATE_B, REVERSE_ROTATE_A_B
}					t_operator;

typedef struct		s_try
{
	int				*first;
	int				*second;
	int				first_length;
	int				second_length;
	t_operator		*operators;
	int				depth;
	int				score;
}					t_try;

typedef struct		s_search
{
	t_priorityqueue	pq;
	int				max_depth;
	t_operators		*solution;
	int				solution_length;
	size_t			permutation_count;
}					t_search;

void				handle_push_swap(int lenght, int *numbers);
void				print_operators(t_operator *operators, int length);
int					compare_tries(t_try *first, t_try *second);

/*
** todo: something to clean up the priorityqueue when we find a
** shorter solution
**
** todo: what to do when there are too many tries on the priority
** queue (too much memory much?)
*/

#endif
