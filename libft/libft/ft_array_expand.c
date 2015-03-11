/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:44:58 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/15 00:34:45 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_array_expand(size_t bytes_before, size_t bytes_after
									, void **data)
{
	void			*new;

	new = malloc(bytes_after);
	ft_memcpy(new, *data, bytes_before);
	free(*data);
	*data = new;
}
