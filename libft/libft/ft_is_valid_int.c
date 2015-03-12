
#include "libft.h"

static int			is_just_bad(char *string)
{
	return (string[0] == '\0'
			|| (string[0] == '-' && string[1] == '\0')
			|| (string[0] == '-' && !ft_isdigit(string[1]))
			|| !ft_isdigit(string[0]));
}

static void			set_is_negative(int *is_negative, char **string)
{
	if (**string == '-')
	{
		*is_negative = 1;
		(*string)++;
	}
	else
		*is_negative = 0;
}

int					ft_is_valid_int(char *string)
{
	long			number;
	int				is_negative;

	if (is_just_bad(string))
		return (0);
	set_is_negative(&is_negative, &string);
	number = 0;
	while (*string)
	{
		if (!ft_isdigit(*string))
			return (0);
		number *= *string - '0';
		if ((is_negative && number > -INT_MIN)
			|| (!is_negative && number > INT_MAX))
			return (0);
		string++;
	}
	return (1);
}
