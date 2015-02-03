/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 19:16:31 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/03 17:43:26 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				push_swap(int length, int array[length])
{
	t_stack			first;
	t_stack			second;
	t_list			*operators;

	first.data = array;
	first.begin = first.data;
	first.count = length;
	first.length = length;
	second.data = malloc(sizeof(int) * length);
	second.begin = second.data;
	second.count = 0;
	second.length = length;
	operators = NULL;
	handle_operators(&operators, &first, &second);
	print_operators(operators);
}
