/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:28:46 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/07 18:42:53 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			cleanup(int *should_delete, int *current
							, int second_offender, int *delete_count)
{
	if (DEBUG) ft_printf("cleanup\n");
	should_delete[*current] = 1;
	should_delete[second_offender] = 1;
	if (*current > 0)
		(*current)--;
	(*delete_count) += 2;
}

static int			should_clean_neighbors(t_operator first, t_operator second)
{
	return ((first == SWAP_A && second == SWAP_A)
			|| (first == SWAP_B && second == SWAP_B)
			|| (first == PUSH_B && second == PUSH_A)
			|| (first == PUSH_A && second == PUSH_B)
			|| (first == ROTATE_A && second == REVERSE_ROTATE_A)
			|| (first == ROTATE_B && second == REVERSE_ROTATE_B)
			|| (first == REVERSE_ROTATE_A && second == ROTATE_A)
			|| (first == REVERSE_ROTATE_B && second == ROTATE_B));
}

static void			create_new_operators(int *length, t_operator **operators
										 , int should_delete[*length]
										 , int delete_count)
{
	t_operator		*new_operators;
	int				old;
	int				new;

	new_operators = malloc((*length - delete_count) * sizeof(t_operator));
	old = 0;
	new = 0;
	while (old < *length)
	{
		if (!should_delete[old])
		{
			new_operators[new] = (*operators)[old];
			new++;
		}
		old++;
	}
	*operators = new_operators;
	*length -= delete_count;
}

void			print_op(t_operator operator);

// todo: combine rotates: ra, rb ==> rr; also reverse
void				cleanup_solution(int *length, t_operator **operators)
{
	int				i;
	int				should_delete[*length];
	int				delete_count;
	int				difference;
	
	ft_bzero(should_delete, *length * sizeof(int));
	delete_count = 0;
	difference = 1;
	i = 0;
	while (i < *length - 1)
	{
		if (DEBUG) ft_printf("i = %d\tfirst second = |", i);
		if (DEBUG) print_op((*operators)[i]);
		if (DEBUG) ft_putchar(' ');
		if (DEBUG) print_op((*operators)[i + difference]);
		if (DEBUG) ft_printf("|\t should_delete[i:i+difference] = [%d, %d]\n"
				  , should_delete[i], should_delete[i + difference]);
		if (!should_delete[i] && !should_delete[i + 1]
			&& should_clean_neighbors((*operators)[i]
									  , (*operators)[i + difference]))
		{
			cleanup(should_delete, &i, i + 1, &delete_count);
			difference += 2;
		}
		else
		{
			i++;
			difference = 1;
		}
	}
	if (DEBUG) ft_printf("delete_count = %d\n", delete_count);
	if (delete_count)
		create_new_operators(length, operators, should_delete, delete_count);
}
