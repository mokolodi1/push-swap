#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/26 19:03:08 by tfleming          #+#    #+#              #
#    Updated: 2015/03/14 19:47:07 by tfleming         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =				push_swap

CC =				gcc
FLAGS =				-Wall -Werror -Wextra -g -O0

SRCS =				srcs/
INCLUDES =			includes/
LIBFT =				libft/
FT_INCLUDES =		$(LIBFT)/includes

COMPILED =			main.o \
					handle_push_swap.o \
					path_finding_push_swap.o \
					permutate.o \
					found_solution.o \
					add_swaps.o \
					add_pushes.o \
					add_rotates.o \
					add_reverse_rotates.o \
					compare_tries.o \
					create_general_try.o \
					free_try.o \
					set_score.o \
					quicksort_push_swap.o \
					partition_to_cutoff.o \
					stack_operations.o \
					get_nth_entry.o \
					get_pivot.o \
					cutoff_reached.o \
					add_to_solution.o \
					convert_entries_to_array.o \
					print_operators.o \
					check_for_exception.o

all: $(NAME)

$(NAME): $(COMPILED)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) -L $(LIBFT) -lft $(COMPILED)
	@echo "made" $(NAME)

$(COMPILED): %.o: $(SRCS)%.c
	@$(CC) -c $(FLAGS) -I $(FT_INCLUDES) -I $(INCLUDES) $< -o $@

clean:
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
