/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 19:16:31 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/02 15:55:03 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** first[one] is the last value of first (same for second[two])
*/

/*
** algorithm note: my goal with this project was to get it to work as
** quickly as possible, not to make it as fast as possible.
*/

void				convert_to_list(int length, int array[length]
									, t_list **first)
{
	t_list			*list;
	int				i;

	i = length - 1;
	while (i >= 0)
	{
		ft_list_push_front(first, array[i]);
		i--;
	}
}

void				push_swap(int length, int array[length])
{
	t_list			*first;
	t_list			*second;

	first = NULL;
	second = NULL;
	convert_to_list(length, array, &first);
	
}
