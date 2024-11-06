# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 11:20:24 by kuzyilma          #+#    #+#              #
#    Updated: 2024/11/03 13:23:31 by kuzyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_isdigit.c				ft_trueprint_reset.c	ft_vavalue_set.c  \
ft_flag_reset.c			ft_mstrchr.c						ft_trueprint_set.c	\
ft_flag_set.c			ft_printf.c				ft_strlen.c				ft_vavalue_reset.c	\
vput_functions/ft_len_putstr.c			vput_functions/ft_putHEXAu.c		vput_functions/ft_puthexa.c \
vput_functions/ft_vputstr.c				vput_functions/ft_vputchar.c \
vput_functions/ft_putnbr.c				vput_functions/ft_putunsnbr.c		vput_functions/ft_putpointer.c\
size_functions/ft_char_size.c			size_functions/ft_deci_int_size.c	size_functions/ft_hexa_size.c \
size_functions/ft_pointer_size.c		size_functions/ft_string_size.c		size_functions/ft_unsint_size.c

CFILESND = ft_isdigit.c					ft_trueprint_reset.c	ft_vavalue_set.c  \
ft_flag_reset.c				ft_mstrchr.c							ft_trueprint_set.c	\
ft_flag_set.c				ft_printf.c				ft_strlen.c				ft_vavalue_reset.c	\
ft_len_putstr.c				ft_putHEXAu.c		ft_puthexa.c \
ft_vputstr.c				ft_vputchar.c \
ft_putnbr.c					ft_putunsnbr.c		ft_putpointer.c\
ft_char_size.c				ft_deci_int_size.c	ft_hexa_size.c \
ft_pointer_size.c			ft_string_size.c	ft_unsint_size.c

OFILES = $(CFILESND:.c=.o) 


CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): 
	cc $(CFLAGS) -c $(CFILES)
	ar rcs $(NAME) $(OFILES)

bonus: all

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re