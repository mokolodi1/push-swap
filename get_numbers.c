/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 11:36:39 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/05 15:22:23 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// change to macros

int					*get_last_number(t_stack *stack)
{
	if (stack->begin + stack->count <= stack->data + stack->length)
		return (stack->begin + stack->count - 1);
	return (stack->data + ((stack->data + stack->length)
							- (stack->begin + stack->count)) - 1);
}

int					*get_before_last_number(t_stack *stack)
{
	if (get_last_number(stack) == stack->data)
		return (stack->data + stack->length - 1);
	return (get_last_number(stack) - 1);
}

int					*get_after_last_number(t_stack *stack)
{
	if (get_last_number(stack) + 1 < stack->data + stack->length)
		return (get_last_number(stack) + 1);
	return (stack->data);
}

int					*get_before_first_number(t_stack *stack)
{
	if (stack->begin > stack->data)
		return (stack->begin - 1);
	return (stack->data + stack->length - 1);
}

int					*get_after_first_number(t_stack *stack)
{
	if (stack->begin + 1 < stack->data + stack->length)
		return (stack->begin + 1);
	return (stack->data);
}
