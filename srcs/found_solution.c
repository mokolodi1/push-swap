/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 19:23:40 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/14 19:23:40 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				found_solution(t_try *try, t_search *search)
{
	if (search->solution)
		free(search->solution);
	search->solution = malloc(try->depth * sizeof(t_operator));
	ft_memcpy(search->solution, try->operators
					, try->depth * sizeof(t_operator));
	search->solution_length = try->depth;
}
