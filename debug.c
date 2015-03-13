/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 14:50:40 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/11 15:33:56 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// nope this file

static void				one_entry(t_entry *entry)
{
	char				*string;

	string = ft_itoa(entry->number);
	ft_putstr(string);
	free(string);
}

static void				multiple_entries(t_entry *entries)
{
	t_entry				*current;

	current = entries;
	one_entry(current);
	current = current->next;
	while (current != entries)
	{
		ft_putchar(' ');
		one_entry(current);
		current = current->next;
	}
}

void					print_entries(t_entry *entries)
{
	ft_putchar('[');
	if (!entries)
		ft_putstr("none");
	else if (entries == entries->next)
		one_entry(entries);
	else
		multiple_entries(entries);
	ft_putchar(']');
}


void				print_debug(t_stack *destination, t_stack *source) // nope
{
	ft_putstr("source =                 ");
	print_entries(source->first);
	ft_putstr("\ndestination =            ");
	print_entries(destination->first);
	ft_putstr("\n\n");
}
