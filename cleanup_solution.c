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
	should_delete[*current] = 1;
	should_delete[second_offender] = 1;
	if (*current > 0)
		(*current)--;
	delete_count += 2;
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

static void			create_new_operators(int length, t_operator **operators
										 , int should_delete[length]
										 , int delete_count)
{
	t_operator		*new_operators;
	int				i;
	int				new;

	new_operators = malloc((length - delete_count) * sizeof(t_operator));
	i = 0;
	new = 0;
	while (i < length)
	{
		if (!should_delete[i])
		{
			new_operators[new] = (*operators)[i];
			new++;
		}
		i++;
	}
	*operators  = new_operators;
}

// todo: combine rotates
void				cleanup_solution(int length, t_operator **operators)
{
	int				i;
	int				should_delete[length];
	int				delete_count;
	
	ft_bzero(should_delete, length * sizeof(int));
	delete_count = 0;
	i = 0;
	while (i < length - 1)
	{
		if (!should_delete[i]
			&& should_clean_neighbors((*operators)[i]
									  , (*operators)[i + 1]))
			cleanup(should_delete, &i, i + 1, &delete_count);
		else
			i++;
	}
	if (delete_count)
		create_new_operators(length, operators, should_delete, delete_count);
}
