# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 09:35:01 by kuzyilma          #+#    #+#              #
#    Updated: 2025/02/03 17:16:01 by kuzyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTUTIL_SRC = ft_atoi.c ft_isdigit.c ft_strchr.c ft_strlcpy.c ft_strlen.c ft_strtrim.c ft_strncmp.c ft_calloc.c ft_bzero.c

UTIL_SRC = ft_input_utils.c ft_data_utils.c ft_general_utils.c

P_SRC = ft_philosophers.c ft_error_check.c ft_routine.c ft_monitor.c

SRC = $(addprefix general/, $(P_SRC)) $(addprefix ft_utils/, $(FTUTIL_SRC)) $(addprefix utils/, $(UTIL_SRC))

CC = cc
CFLAGS = -Wall -Werror -Wextra

OSRC = $(SRC:.c=.o)

NAME = philo


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
	
