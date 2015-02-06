/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 19:00:08 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/05 15:52:55 by tfleming         ###   ########.fr       */
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

# define MAX_DEPTH		16;
# define LAST_OPERATOR(SEARCH)  (*(SEARCH)->operators + (SEARCH)->current - 1)
# define GET_LAST_NUMBER(STACK) \
	(((STACK)->begin + (STACK)->count <= (STACK)->data + (STACK)->length) \
		? ((STACK)->begin + (STACK)->count - 1)							  \
		: ((STACK)->data + (((STACK)->begin + (STACK)->count) \
								- ((STACK)->data + (STACK)->length)) - 1))

# define GET_BEFORE_LAST_NUMBER(STACK) \
	((GET_LAST_NUMBER(STACK) == (STACK)->data) \
	? ((STACK)->data + (STACK)->length - 1) \
	: (GET_LAST_NUMBER(STACK) - 1))

# define GET_AFTER_LAST_NUMBER(STACK) \
	((GET_LAST_NUMBER(STACK) + 1 < (STACK)->data + (STACK)->length)	\
		? (GET_LAST_NUMBER(STACK) + 1) \
		: ((STACK)->data))

# define GET_BEFORE_FIRST_NUMBER(STACK) \
	((stack->begin > stack->data) \
		? (stack->begin - 1) \
		: (stack->data + stack->length - 1))

/* if (stack->begin + 1 < stack->data + stack->length) */
/* 		return (stack->begin + 1); */
/* 	return (stack->data); */

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
void				print_operators(t_operator *operators, int length);
int					*get_last_number(t_stack *stack);
int					*get_before_last_number(t_stack *stack);
int					*get_after_last_number(t_stack *stack);
int					*get_before_first_number(t_stack *stack);
int					*get_after_first_number(t_stack *stack);

#endif
