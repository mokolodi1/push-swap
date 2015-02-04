/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 19:11:06 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/04 19:13:36 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					*get_last_pointer(t_stack *stack)
{
	if (stack->begin + stack->count <= stack->data + stack->length)
		return (stack->begin + stack->count - 1);
	// loops around
	// start here tomorrow
}
