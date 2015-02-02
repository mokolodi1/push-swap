/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 11:45:56 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/02 12:02:08 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array				*ft_array_new(size_t length, size_t size)
{
	t_array			*new;

	new = malloc(sizeof(t_array));
	new->length = length;
	new->size = size;
	new->data = malloc(length * size);
	return (new);
}
