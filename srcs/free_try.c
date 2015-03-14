/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_try.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 19:35:26 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/14 19:35:26 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				free_try(t_try *try)
{
	if (try->first[try->first_length])
		try->first[try->first_length]--;
	else
		free(try->first);
	if (try->second[try->second_length])
		try->second[try->second_length]--;
	else
		free(try->second);
	free(try->operators);
	free(try);
}
