#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/26 19:03:08 by tfleming          #+#    #+#              #
#    Updated: 2015/02/05 12:46:28 by tfleming         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =				push_swap

CC =				gcc
FLAGS =				-Wall -Werror -Wextra -O3

LIBFT =				"libft/"
HEADER =			$(FT_SRC_DIR)libft.h

COMPILED =			main.o \
					push_swap.o \
					print_operators.o \
					calculate_operators.o \
					try_swap.o \
					try_push.o \
					try_rotates.o \
					get_numbers.o

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
