#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/26 19:03:08 by tfleming          #+#    #+#              #
#    Updated: 2015/03/07 18:40:34 by tfleming         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =				push_swap

CC =				gcc
FLAGS =				-Wall -Werror -Wextra -g -O0

LIBFT =				"libft/"
HEADER =			$(FT_SRC_DIR)libft.h

COMPILED =			main.o \
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
				get_pivot.o \
				cutoff_reached.o \
				add_to_solution.o \
				cleanup_solution.o \
				print_entries.o \
				print_operators.o

all: $(NAME)

$(NAME): $(COMPILED)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) -L $(LIBFT) -lft $(COMPILED)
	@echo "made" $(NAME)

$(COMPILED): %.o: %.c
	@$(CC) -c $(FLAGS) -I $(LIBFT) $< -o $@

clean:
	@make -C $(LIBFT) clean
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@make -C $(LIBFT) fclean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
