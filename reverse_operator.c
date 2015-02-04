/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 10:30:14 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/04 10:55:48 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_operator	reverse_rotate(t_operator operator)
{
	if (operator == ROTATE_A)
		return (REVERSE_ROTATE_A);
	if (operator == ROTATE_B)
		return (REVERSE_ROTATE_B);
	if (operator == ROTATE_A_B)
		return (REVERSE_ROTATE_A_B);
	if (operator == REVERSE_ROTATE_A)
		return (ROTATE_A);
	if (operator == REVERSE_ROTATE_B)
		return (ROTATE_B);
	return (ROTATE_A_B);
}

t_operator			reverse_operator(t_operator operator)
{
	if (operator <= SWAP_S)
		return (operator);
	if (operator <= PUSH_B)
	{
		if (operator == PUSH_A)
			return (PUSH_B);
		return (PUSH_A);
	}
	return (reverse_rotate(operator));
}
