#include "push_swap.h"

/*
** quickselect (as per en.wikipedia.org/wiki/Quickselect)
*/

static void			move_entries_to_array(t_entry *entries, int length
													, int *numbers)
{
	int				i;

	i = 0;
	while (i < length)
	{
		numbers[i] = entries->number;
		entries = entries->next;
		i++;
	}
}

static int			quickselect(int *numbers, int length, int from_highest)
{
	int				i;
	int				st;

	i = 0;
	st = 0;
	while (i < length - 1)
	{
		if (numbers[i] <= numbers[length - 1])
		{
			ft_intswp(numbers + i, numbers + st);
			st++;
		}
		i++;
	}
	ft_intswp(numbers + length - 1, numbers + st);
	if (st == from_highest)
		return (numbers[st]);
	if (st > from_highest)
		return (quickselect(numbers, st, from_highest));
	return (quickselect(numbers + st, length - st, from_highest - st));
}

int					get_pivot(t_entry *entries, int length)
{
	int				numbers[length];
	
	move_entries_to_array(entries, length, numbers);
	return (quickselect(numbers, length, length / 2));
}
