# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 11:20:24 by kuzyilma          #+#    #+#              #
#    Updated: 2024/10/18 09:37:47 by kuzyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_isalnum.c    ft_isdigit.c    ft_memset.c     ft_strlcpy.c    ft_toupper.c \
ft_isalpha.c    ft_isprint.c    ft_strchr.c     ft_strlen.c		ft_strrchr.c		\
ft_isascii.c    ft_memmove.c    ft_strlcat.c    ft_tolower.c	ft_bzero.c	ft_memcpy.c	\
ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c	ft_atoi.c	ft_calloc.c \
ft_strdup.c		ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c	ft_itoa.c \
ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	\
ft_putnbr_fd.c

BONUS = ft_lstadd_back_bonus.c  ft_lstdelone_bonus.c    ft_lstmap_bonus.c \
ft_lstadd_front_bonus.c ft_lstiter_bonus.c      ft_lstnew_bonus.c  \
ft_lstclear_bonus.c     ft_lstlast_bonus.c      ft_lstsize_bonus.c  

OFILES = $(CFILES:.c=.o)
BONUSOFILES = $(BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(CFILES)
	ar rcs $(NAME) $(OFILES)

bonus: 
	gcc $(CFLAGS) -c $(BONUS)
	ar rcs $(NAME) $(BONUSOFILES)

clean:
	rm -f $(OFILES) $(BONUSOFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re