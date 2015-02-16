/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:25:15 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/13 16:34:55 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			print_op(t_operator operator)
{
	if (operator == SWAP_A)
		fprintf(stdout, " sa");
	else if (operator == SWAP_B)
		fprintf(stdout, " sb");
	else if (operator == SWAP_S)
		fprintf(stdout, " ss");
	else if (operator == PUSH_A)
		fprintf(stdout, " pa");
	else if (operator == PUSH_B)
		fprintf(stdout, " pb");
	else if (operator == ROTATE_A)
		fprintf(stdout, " ra");
	else if (operator == ROTATE_B)
		fprintf(stdout, " rb");
	else if (operator == ROTATE_A_B)
		fprintf(stdout, " rr");
	else if (operator == REVERSE_ROTATE_A)
		fprintf(stdout, "rra");
	else if (operator == REVERSE_ROTATE_B)
		fprintf(stdout, "rrb");
	else if (operator == REVERSE_ROTATE_A_B)
		fprintf(stdout, "rrr");
	else
		fprintf(stdout, "nope");
}

void				print_operators(int length, t_operator *operators)
{
	int				i;

	//fprintf(stdout, "\r\033[2K");
	i = 0;
	while (i < length - 1)
	{
		print_op(operators[i]);
		//ft_putchar(' ');
		fprintf(stdout, " ");
		i++;
	}
	if (length > 0)
		print_op(operators[i]);
}
