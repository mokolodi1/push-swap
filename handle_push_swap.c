/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 13:46:58 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/14 14:00:36 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			should_cleanup(int left, int right, t_operator *solution)
{
	t_operator		*left_op;
	t_operator		*right_op;

	left_op = solution[left];
	right_op = solution[right];
	if ((left_op == ROTATE_A && right_op == REVERSE_ROTATE_A)
		|| (left_op == REVERSE_ROTATE_A && right_op == ROTATE_A)
		|| (left_op == ROTATE_B && right_op == REVERSE_ROTATE_B)
		|| (left_op == REVERSE_ROTATE_B && right_op == ROTATE_B))
		return (1);
	return (0);
}

static void			rotate_cleanup(int *solution_length
								   , t_operator **solution)
{
	int				should_delete[*solution_length];
	int				i;
	int				left;
	int				right;
	int				deleted;

	ft_bzero(should_delete, *solution_length * sizeof(int));
	deleted = 0;
	i = 0;
	while (i < *solution_length - 1)
	{
		left = i;
		right = left + 1;
		while (should_cleanup(left, right, *solution))
		{
			should_delete[left] = 1;
			should_delete[right] = 1;
			left--;
			right++;
			deleted += 2;
		}
		i++;
	}
	i = 0;
	// move to an other buffer
}

void				handle_push_swap(int length, int *numbers)
{
	t_operator		*solution;
	int				solution_length;

	if (length <= PATH_FINDING_MAX_LENGTH)
		path_finding_push_swap(length, numbers
								, &solution, &solution_length);
	else
	{
		if (!check_for_exception(length, numbers, &solution, &solution_length))
			quicksort_push_swap(length, numbers, &solution, &solution_length);
	}
	rotate_cleanup(&solution_length, &solution);
	print_operators(solution_length, solution);
	ft_putchar('\n');
}
