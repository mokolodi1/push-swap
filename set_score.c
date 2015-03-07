/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 00:54:19 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/07 12:47:21 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				out_of_place(t_try *try, int multiplier)
{
	int				i;

	i = try->second_length - 1;
	while (i >= 0)
	{
		try->score += (i + try->second[i] + 1) * multiplier;
		i--;
	}
	i = 0;
	while (i < try->first_length)
	{
		try->score += ft_abs((try->first[i] - try->second_length) - i) * multiplier;
		i++;
	}
}

void				sortedness(t_try *try, int sorted, int not_sorted)
{
	int				i;
	
	i = 1;
	while (i < try->second_length)
	{
		try->sortedness += (try->second[i - 1] > try->second[i])
										? sorted : not_sorted;
		i++;
	}
	if (try->first_length && try->second_length)
		try->sortedness += (try->second[0] < try->first[0]) ? sorted : not_sorted;
	i = 1;
	while (i < try->first_length)
	{
		try->sortedness += (try->first[i - 1] < try->first[i])
										? sorted : not_sorted;
		i++;
	}
}

void				set_score(t_try *try)
{
	try->score = 0;
	try->score += try->depth * 2;
	try->score += try->second_length;
	try->sortedness = 0;
	sortedness(try, -1, 1);
	try->score += try->sortedness * 3;
}
