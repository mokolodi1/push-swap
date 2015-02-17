/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 00:54:19 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/15 00:55:24 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** compare the array indexes with the contents
*/

static void			penalize_depth(t_try *try, int multiplier)
{
	try->score += try->depth * multiplier;
}

static void			penalize_out_of_place(t_try *try)
{
	int				i;

	i = try->second_length - 1;
	while (i >= 0)
	{
		try->score += i + try->second[i] + 1;
		i--;
	}
	i = 0;
	while (i < try->first_length)
	{
		try->score += ft_abs((try->first[i] - try->second_length) - i);
		i++;
	}
}

void				set_score(t_try *try)
{
	try->score = 0;
	penalize_depth(try, 2);
	penalize_out_of_place(try);
	if (try->score < -100 || try->score > 100)
	{
		printf("wat\t");
		print_try(try);
	}
}
