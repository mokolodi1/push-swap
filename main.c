/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 18:59:56 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/02 18:09:21 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int			maximum_number(int length, int numbers[length])
{
	int				maximum;
	int				i;

	maximum = numbers[0];
	i = 1;
	while (i < length)
	{
		if (numbers[i] > maximum)
			maximum = numbers[i];
		i++;
	}
	return (maximum);
}

static int			minimum_number(int length, int numbers[length])
{
	int				minimum;
	int				i;

	minimum = numbers[0];
	i = 1;
	while (i < length)
	{
		if (numbers[i] < minimum)
			minimum = numbers[i];
		i++;
	}
	return (minimum);
}

static void			validate_arguments(int length, int numbers[length]
									   , int minimum, int maximum)
{
	t_bool			switches[maximum - minimum + 2];
	int				i;
	int				index;

	ft_bzero(switches, sizeof(t_bool) * (maximum - minimum + 2));
	i = 0;
	while (i < length)
	{
		index = numbers[i] - minimum;
		if (switches[index])
		{
			ft_putendl("Error");
			exit(1);
		}
		else
			switches[index] = 1;
		i++;
	}
}

int					main(int argc, char **argv)
{
	argc--;
	argv++;
	if (argc > 0)
	{
		parse_arguments(argc, argv, numbers);
		validate_arguments(argc, numbers, minimum_number(argc, numbers)
							, maximum_number(argc, numbers));
		push_swap(argc, numbers);
	}
	else
	{
		ft_putendl("Error");
		exit(1);
	}
	return (0);
}
