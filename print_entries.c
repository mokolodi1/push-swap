#include "push_swap.h"

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
