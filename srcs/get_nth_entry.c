/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nth_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 19:34:26 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/14 19:35:04 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_entry		*get_nth_entry(t_entry *first, int n)
{
	int				i;

	i = 1;
	while (i < n)
	{
		first = first->next;
		i++;
	}
	return (first);
}
