# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 09:35:01 by kuzyilma          #+#    #+#              #
#    Updated: 2025/02/04 16:33:07 by kuzyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTUTIL_SRC = ft_atoi.c ft_isdigit.c ft_strchr.c ft_strlcpy.c ft_strlen.c ft_strtrim.c ft_strncmp.c ft_calloc.c ft_bzero.c

UTIL_SRC = kzy_input_utils.c kzy_data_utils.c kzy_general_utils.c

P_SRC = kzy_philosophers.c kzy_error_check.c kzy_routine.c kzy_monitor.c kzy_sem_error.c

SRC = $(addprefix general/, $(P_SRC)) $(addprefix ft_utils/, $(FTUTIL_SRC)) $(addprefix utils/, $(UTIL_SRC))

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

OSRC = $(SRC:.c=.o)

NAME = philo_bonus


all: $(NAME)

$(NAME): $(OSRC) 
	$(CC) $(CFLAGS) $(OSRC) -o $(NAME)

leak: $(OSRC)
	$(CC) $(CFLAGS) -fsanitize=address $(OSRC) -o $(NAME)
	
clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)
re: fclean all

main: all
	rm -f $(OSRC) 
	clear

mainleak: leak
	rm -f $(OSRC) 
	clear

.PHONY: all clean fclean re main leak mainleak
	
