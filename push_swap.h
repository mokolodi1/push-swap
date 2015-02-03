/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 19:00:08 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/03 17:44:53 by tfleming         ###   ########.fr       */
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

void				push_swap(int length, int array[length]);
void				handle_operators(t_list **operators
									 , t_stack *first, t_stack *second);
void				print_operators(t_list *operators);

#endif
