/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 18:59:56 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 19:37:15 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			parse_arguments(int length, char **arguments
										, t_uint numbers[length])
{
	(void)length;
	(void)arguments;
	(void)numbers;
}

static t_uint			maximum_number(int length, t_uint numbers[length])
{
	t_uint			maximum;

	maximum = 0;
	(void)length;
	(void)numbers;
	return (maximum);
}

static void			validate_arguments(int length, t_uint numbers[length])
{
	t_uint			maximum;
	t_bool			switches[(maximum = maximum_number(length, numbers))];

	(void)length;
	(void)numbers;
	(void)maximum;
	(void)switches;
}

int					main(int argc, char **argv)
{
	t_uint			numbers[argc];

	if (argc >= 2)
	{
		parse_arguments(argc, argv, numbers);
		validate_arguments(argc, numbers);
		push_swap(argc, numbers);
	}
	else
	{
		ft_putendl("Error");
		exit(1);
	}
	return (0);
}
