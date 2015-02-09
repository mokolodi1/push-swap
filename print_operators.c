/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:25:15 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/09 16:35:07 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			print_op(t_operator operator)
{
	if (operator == SWAP_A)
		ft_putstr("sa");
	else if (operator == SWAP_B)
		ft_putstr("sb");
	else if (operator == SWAP_S)
		ft_putstr("ss");
	else if (operator == PUSH_A)
		ft_putstr("pa");
	else if (operator == PUSH_B)
		ft_putstr("pb");
	else if (operator == ROTATE_A)
		ft_putstr("ra");
	else if (operator == ROTATE_B)
		ft_putstr("rb");
	else if (operator == ROTATE_A_B)
		ft_putstr("rr");
	else if (operator == REVERSE_ROTATE_A)
		ft_putstr("rra");
	else if (operator == REVERSE_ROTATE_B)
		ft_putstr("rrb");
	else if (operator == REVERSE_ROTATE_A_B)
		ft_putstr("rrr");
	else
		ft_putstr("nope");
}

void				print_operators(t_operator *operators, int length)
{
	int				i;

	i = 0;
	while (i < length - 1)
	{
		print_op(operators[i]);
		ft_putchar(' ');
		i++;
	}
	if (length > 0)
		print_op(operators[i]);
	ft_putchar('\n');
}
