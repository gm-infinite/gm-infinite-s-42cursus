# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 09:35:01 by kuzyilma          #+#    #+#              #
#    Updated: 2025/01/14 11:21:17 by kuzyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_push_swap.c ft_isinput_correct.c ft_stack_a_set.c ft_lstps_utils.c \
the_functions.c ft_lstps_utils2.c ft_three_element_sort.c \
ft_is_sorted.c turk_alg.c value_calc.c getbvalue.c turk_alg_put_back.c \
getavalue.c

CC = cc
CFLAGS = -Wall -Werror -Wextra

OSRC = $(SRC:.c=.o)

NAME = push_swap

LIBFT = ./libft/libft.a

all: $(NAME)

$(LIBFT):
		make -C ./libft

$(NAME): $(OSRC) $(LIBFT)
	$(CC) $(CFLAGS) $(OSRC) $(LIBFT) -o $(NAME)
	
clean:
	make clean -C ./libft
	rm -f $(OSRC)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

main: all
	make clean -C ./libft
	rm -f $(OSRC)
	clear

.PHONY: all clean fclean re main
	