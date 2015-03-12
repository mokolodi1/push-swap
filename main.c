/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 18:59:56 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/11 17:41:51 by tfleming         ###   ########.fr       */
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

static void			validate_arguments(int length, int numbers[length])
{
	int				copy[length];
	int				i;

	ft_memcpy(copy, numbers, length * sizeof(int));
	ft_quicksort(length, copy);
	i = 0;
	while (i < length - 1)
	{
		if (copy[i] == copy[i + 1])
		{
			ft_putendl("Error");
			exit(1);
		}
		i++;
	}
}

static void			handle_push_swap(int length, int *numbers)
{
	t_operator		*solution;
	int				solution_length;
	int				was_exception;

	was_exception = check_for_exception(length, numbers
										, &solution, &solution_length);
	if (!was_exception)
	{
		if (length <= PATH_FINDING_MAX_LENGTH)
			path_finding_push_swap(length, numbers
									, &solution, &solution_length);
		else
			quicksort_push_swap(length, numbers, &solution, &solution_length);
	}
	print_operators(solution_length, solution);
	ft_putchar('\n');
}

int					main(int argc, char **argv)
{
	int				*numbers;

	argc--;
	argv++;
	if (argc > 0)
	{
		numbers = malloc(argc * sizeof(int));
		parse_arguments(argc, argv, numbers);
		validate_arguments(argc, numbers);
		handle_push_swap(argc, numbers);
	}
	else
	{
		ft_putendl("Error");
		exit(1);
	}
	return (0);
}
