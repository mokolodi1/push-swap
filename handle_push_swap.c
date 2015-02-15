/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 19:22:05 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/15 01:00:08 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				handle_push_swap(int length, int *numbers)
{
	t_search		search;

	ft_bzero(&search, sizeof(t_search));
	search->pq = ft_pq_create_new(&compare_tries);
	search->max_depth = INT_MAX;
	while (!search->solution)
		permutate(search);
	print_operators(search->solution_length, search->solution);
	ft_putchar('\n');
}
