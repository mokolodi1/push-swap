/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 18:59:56 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/14 13:48:00 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			validate_arguments(int length, char **arguments)
{
	int				i;

	i = 0;
	while (i < length)
	{
		if (!ft_is_valid_int(arguments[i]))
			ft_putendl_exit("Error", 1);
		i++;
	}
}

static void			parse_arguments(int length, char **arguments
										, int numbers[length])
{
	int				i;

	i = 0;
	while (i < length)
	{
		numbers[i] = ft_atoi(arguments[i]);
		i++;
	}
}

static void			validate_numbers(int length, int numbers[length])
{
	int				copy[length];
	int				i;

	ft_memcpy(copy, numbers, length * sizeof(int));
	ft_quicksort(length, copy);
	i = 0;
	while (i < length - 1)
	{
		if (copy[i] == copy[i + 1])
			ft_putendl_exit("Error", 1);
		i++;
	}
}

int					main(int argc, char **argv)
{
	int				*numbers;

	argc--;
	argv++;
	validate_arguments(argc, argv);
	numbers = malloc(argc * sizeof(int));
	parse_arguments(argc, argv, numbers);
	validate_numbers(argc, numbers);
	handle_push_swap(argc, numbers);
	return (0);
}
