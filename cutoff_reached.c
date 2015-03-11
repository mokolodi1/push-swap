/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutoff_reached.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:45:30 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/11 15:49:56 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				cutoff_reached(t_stack *stack, int length)
{
	if (DEBUG) ft_printf("\ncutoff_reached:\n");
	if (length == 0)
		return ;
	if (length == 1)
		rotate(stack);
	else if (length == 2)
	{
		if (stack->first->number > stack->first->next->number)
			swap(stack);
		rotate(stack);
		rotate(stack);
	}
	else
	{
		ft_printf("cutoff_reached called but length is incorrect: %d\n"
					, length);
		exit(1);
	}
}
