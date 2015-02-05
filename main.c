/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 18:59:56 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/05 15:40:09 by tfleming         ###   ########.fr       */
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

static void			set_minimum_maximum(int length, int *numbers
										, int *minimum, int *maximum)
{
	int				min;
	int				max;
	int				i;

	min = numbers[0];
	max = numbers[0];
	i = 1;
	while (i < length)
	{
		if (numbers[i] < min)
			min = numbers[i];
		else if (numbers[i] > max)
			max = numbers[i];
		i++;
	}
	*minimum = min;
	*maximum = max;
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
	int				minimum;
	int				maximum;
	int				numbers[argc - 1];

	argc--;
	argv++;
	if (argc > 0)
	{
		parse_arguments(argc, argv, numbers);
		set_minimum_maximum(argc, numbers, &minimum, &maximum);
		validate_arguments(argc, numbers, minimum, maximum);
		push_swap(argc, numbers);
	}
	else
	{
		ft_putendl("Error");
		exit(1);
	}
	return (0);
}
