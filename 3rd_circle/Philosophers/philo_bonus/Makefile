# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 09:35:01 by kuzyilma          #+#    #+#              #
#    Updated: 2025/02/07 11:49:38 by kuzyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTUTIL_SRC = ft_atoi_bonus.c ft_isdigit_bonus.c ft_strchr_bonus.c ft_strlcpy_bonus.c ft_strlen_bonus.c ft_strtrim_bonus.c ft_strncmp_bonus.c ft_calloc_bonus.c ft_bzero_bonus.c

UTIL_SRC = ft_input_utils_bonus.c ft_data_utils_bonus.c ft_general_utils_bonus.c

P_SRC = ft_philosophers_bonus.c ft_error_check_bonus.c ft_routine_bonus.c ft_monitor_bonus.c ft_sem_error_bonus.c


SRC = $(addprefix general/, $(P_SRC)) $(addprefix ft_utils/, $(FTUTIL_SRC)) $(addprefix utils/, $(UTIL_SRC))

CC = cc
CFLAGS = -Wall -Werror -Wextra

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
	
