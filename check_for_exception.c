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
** see note in main.c
*/

int					check_for_exception(int length, int *numbers
										, t_operator **solution
										, int *solution_length)
{
	int				sorted[length];

	ft_memcpy(sorted, numbers, length * sizeof(int));
	ft_quicksort(length, sorted);
//	if (length > 2 && sorted[
	return (0);
}
