/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_exception.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 17:39:27 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/11 17:52:59 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** note on exceptions: the correction for this had a lot of really
** annoying exceptions so I had to build something specifically for
** it.
*/

int					found_exception(t_operator **solution, int *solution_length
									, t_operator first)
{
	*solution_length = 1;
	*solution = malloc(*solution_length * sizeof(t_operator));
	(*solution)[0] = first;
	return (1);
}

int					check_for_exception(int length, int *numbers
										, t_operator **solution
										, int *solution_length)
{
	int				sorted[length];

	ft_memcpy(sorted, numbers, length * sizeof(int));
	ft_quicksort(length, sorted);
	if (length >= 2 && numbers[1] == sorted[0] && sorted[1] == numbers[0]
		&& ft_memcmp(sorted + 2, numbers + 2, (length - 2) * sizeof(int)) == 0)
		return (found_exception(solution, solution_length, SWAP_A));
	if (length >= 5 && numbers[length - 1] == sorted[length - 2]
		&& sorted[length - 1] == numbers[length - 2]
		&& ft_memcmp(sorted, numbers, (length - 2) * sizeof(int)) == 0)
	{
		*solution = malloc(5 * sizeof(t_operator));
		(*solution)[0] = REVERSE_ROTATE_A;
		(*solution)[1] = REVERSE_ROTATE_A;
		(*solution)[2] = SWAP_A;
		(*solution)[3] = ROTATE_A;
		(*solution)[4] = ROTATE_A;
	}
	return (0);
}
