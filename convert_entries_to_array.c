/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_entries_to_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 14:35:07 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/11 14:58:44 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				convert_entries_to_array(t_entry *entries, int length
													, int *numbers)
{
	int				i;

	i = 0;
	while (i < length)
	{
		numbers[i] = entries->number;
		entries = entries->next;
		i++;
	}
}
