# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 13:44:32 by kuzyilma          #+#    #+#              #
#    Updated: 2024/12/13 12:21:15 by kuzyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)


all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS_SERVER) libft/libft.a -o $(SERVER)

$(CLIENT): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS_CLIENT) libft/libft.a -o $(CLIENT)

$(LIBFT):
		make -C ./libft

bonus: $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) libft/libft.a -o $(SERVER)
		$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) libft/libft.a -o $(CLIENT)

clean:	
		make clean -C ./libft
		rm -rf $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean:	clean
		make fclean -C ./libft
		rm -rf $(SERVER) $(CLIENT)

re:	fclean all

.PHONY: all bonus clean fclean re