/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 16:00:45 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/11 10:57:28 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** need to add randomization to ensure n*lg(n) time
*/

void				ft_quicksort(int length, int *array)
{
	int				lower;
	int				upper;
	int				partition;

	if (length < 2)
		return ;
	partition = array[length / 2];
	lower = 0;
	upper = length - 1;
	while (1)
	{
		while (array[lower] < partition)
			lower++;
		while (partition < array[upper])
			upper--;
		if (lower >= upper)
			break ;
		ft_intswp(array + lower, array + upper);
		lower++;
		upper--;
	}
	ft_quicksort(lower, array);
	ft_quicksort(length - lower, array + lower);
}
