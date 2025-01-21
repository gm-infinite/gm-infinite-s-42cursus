# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 09:35:01 by kuzyilma          #+#    #+#              #
#    Updated: 2025/01/21 11:21:53 by kuzyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_push_swap.c ft_isinput_correct.c ft_stack_a_set.c ft_lstps_utils.c \
the_functions.c ft_lstps_utils2.c ft_three_element_sort.c \
ft_is_sorted.c turk_alg.c value_calc.c getbvalue.c turk_alg_put_back.c \
getavalue.c ft_normalize_argv.c

BSRCP = checker_bonus.c             ft_lstps_utils2_bonus.c     ft_stack_a_set_bonus.c      the_functions_bonus.c \
ft_is_sorted_bonus.c        ft_lstps_utils_bonus.c      get_next_line_bonus.c \
ft_isinput_correct_bonus.c  ft_normalize_argv_bonus.c the_functions2_bonus.c

BSRC = $(addprefix bonus/, $(BSRCP))

CC = cc
CFLAGS = -Wall -Werror -Wextra

OSRC = $(SRC:.c=.o)

BOSRC = $(BSRC:.c=.o)

NAME = push_swap

LIBFT = ./libft/libft.a

all: $(NAME)

$(LIBFT):
		make -C ./libft

$(NAME): $(OSRC) $(LIBFT)
	$(CC) $(CFLAGS) $(OSRC) $(LIBFT) -o $(NAME)
	
clean:
	make clean -C ./libft
	rm -f $(OSRC) $(BOSRC)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME) checker

re: fclean all

main: all bonus
	make clean -C ./libft
	rm -f $(OSRC) $(BOSRC)
	clear

bonus: $(LIBFT) $(BOSRC)
	$(CC) $(CFLAGS) $(BOSRC) $(LIBFT) -o checker


.PHONY: all clean fclean re main bonus
	