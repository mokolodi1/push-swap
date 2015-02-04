/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 19:00:08 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/04 12:01:07 by tfleming         ###   ########.fr       */
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
# include <stdio.h> // nope

# define MAX_DEPTH			3;

typedef char		t_bool;

/*
** end is the last in data
*/

typedef struct		s_stack
{
	int				*data;
	int				*begin;
	int				count;
	int				length;
}					t_stack;

typedef enum		e_operator
{
	SWAP_A, SWAP_B, SWAP_S
	, PUSH_A, PUSH_B
	, ROTATE_A, ROTATE_B, ROTATE_A_B
	, REVERSE_ROTATE_A, REVERSE_ROTATE_B, REVERSE_ROTATE_A_B
}					t_operator;

typedef struct		s_search
{
	int				maximum;
	int				current;
	t_operator		*operators;
	t_operator		*solution;
	int				solution_length;
}					t_search;

void				push_swap(int length, int array[length]);
void				calculate_operators(t_search *search
										, t_stack *first, t_stack *second);
void				try_swap(t_search *search, t_stack *first, t_stack *second);
void				try_push(t_search *search, t_stack *first, t_stack *second);
void				try_rotate(t_search *search
										, t_stack *first, t_stack *second);
void				try_reverse_rotate(t_search *search
										, t_stack *first, t_stack *second);
t_operator			reverse_operator(t_operator operator);
void				print_operators(t_operator *operators, int length);

#endif
