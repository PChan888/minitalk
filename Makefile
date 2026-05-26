# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/13 00:24:51 by kaichan           #+#    #+#              #
#    Updated: 2026/05/27 03:03:06 by kaichan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_D = Libft
LIBFT = $(LIBFT_D)/libft.a

SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_SERVER_B = server_bonus.c
SRCS_CLIENT_B = client_bonus.c

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_D)

$(SERVER): server.c $(LIBFT)
	$(CC) $(CFLAGS) server.c -L$(LIBFT_D) -lft -o $(SERVER)

$(CLIENT): client.c $(LIBFT)
	$(CC) $(CFLAGS) client.c -L$(LIBFT_D) -lft -o $(CLIENT)

bonus: $(LIBFT) server_bonus.c client_bonus.c
	$(CC) $(CFLAGS) server_bonus.c -L$(LIBFT_D) -lft -o $(SERVER)
	$(CC) $(CFLAGS) client_bonus.c -L$(LIBFT_D) -lft -o $(CLIENT)

clean:
	make -C $(LIBFT_D) clean
	rm -f $(SERVER) $(CLIENT)

fclean: clean
	make -C $(LIBFT_D) fclean

re: fclean all

.PHONY: all clean fclean re

