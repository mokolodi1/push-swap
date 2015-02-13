/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:40:52 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/13 16:42:05 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_array_reverse(size_t length, int *array)
{
	size_t			i;

	i = 0;
	while (i < length / 2)
	{
		ft_intswp(array + i, array + length - 1 - i);
		i++;
	}
}
