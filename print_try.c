#include "push_swap.h"

// this is a debug file

void				print_try(t_try *try)
{
	int				printed;

	fprintf(stdout, "[");
	printed = 0;
	for (int i = 0; i < try->first_length - 1; i++)
		printed += fprintf(stdout, "%4d", try->first[i]);
	if (try->first_length)
		printed += fprintf(stdout, "%4d", try->first[try->first_length - 1]);
	fprintf(stdout, "]");
	for (int i = 0; i < 40 - printed; i++)
		printf(" ");
	fprintf(stdout, "[");
	printed = 0;
	for (int i = 0; i < try->second_length - 1; i++)
		printed += fprintf(stdout, "%4d ", try->second[i]);
	if (try->second_length)
		printed += fprintf(stdout, "%4d", try->second[try->second_length - 1]);
	fprintf(stdout, "]");
	for (int i = 0; i < 40 - printed; i++)
		printf(" ");
	fprintf(stdout, "score = %+5d ", try->score);
	print_operators(try->depth, try->operators);
	fprintf(stdout, "\n");
}
