/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 19:22:38 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/05 20:18:10 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		push(t_stack *source, t_stack *destination)
{
	int		*source_last;
	int		*destination_after_last;

	if (!source->count)
		return (0);
	
	source_last = get_last_number(source);
	destination_after_last = get_after_last_number(destination);
	*destination_after_last = *source_last;
	source->count--;
	destination->count++;
	return (1);
}

void				print_array(int *numbers, int length)
{
	int				i;

	printf("[");
	i = 0;
	while (i < length - 1)
	{
		printf("%d ", numbers[i]);
		i++;
	}
	printf("%d]\n", numbers[i]);
}

int					main(void)
{
	t_stack			source;
	t_stack			destination;
	int				first[] = {11, 12, 13, 14, 15, 16, 17, 18};
	int				first_len = 8;
	int				second[] = {21, 22, 23, 24, 25, 26, 27, 28};
	int				second_len = 8;

	source.data = first;
	source.length = first_len;
	source.begin = source.data + 5;
	source.count = 4;

	destination.data = second;
	destination.length = second_len;
	destination.begin = destination.data + 5;
	destination.count = 4;
	
	printf("\nbefore:\n");
	print_array(first, first_len);
	print_array(second, second_len);
	
	push(&source, &destination);
	printf("\nafter:\n");
	print_array(first, first_len);
	print_array(second, second_len);

	push(&destination, &source);
	printf("\nlast:\n");
	print_array(first, first_len);
	print_array(second, second_len);
	return (0);
}
	
