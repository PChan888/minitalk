# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/13 00:24:51 by kaichan           #+#    #+#              #
#    Updated: 2026/05/28 03:25:37 by kaichan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server
CLIENT = client

SERVER_B = server_bonus
CLIENT_B = client_bonus

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

$(SERVER): $(SRCS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_SERVER) -L$(LIBFT_D) -lft -o $(SERVER)

$(CLIENT): $(SRCS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_CLIENT) -L$(LIBFT_D) -lft -o $(CLIENT)

bonus: $(LIBFT) $(SERVER_B) $(CLIENT_B)

$(SERVER_B): $(SRCS_SERVER_B) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_SERVER_B) -L$(LIBFT_D) -lft -o $(SERVER_B)

$(CLIENT_B): $(SRCS_CLIENT_B) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_CLIENT_B) -L$(LIBFT_D) -lft -o $(CLIENT_B)

clean:
	make -C $(LIBFT_D) clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

fclean: clean
	make -C $(LIBFT_D) fclean

re: fclean all

