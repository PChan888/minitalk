# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/13 00:24:51 by kaichan           #+#    #+#              #
#    Updated: 2026/05/13 18:52:33 by kaichan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server

CLIENT = client

CC = cc

CFLAGS = -Wall -Wextra -Werror
LIBFT_D = Libft
LIBFT = $(LIBFT_D)/libft.a

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_D)

$(SERVER): server.c $(LIBFT)
	$(CC) $(CFLAGS) server.c -L$(LIBFT_D) -lft -o $(SERVER)

$(CLIENT): client.c $(LIBFT)
	$(CC) $(CFLAGS) client.c -L$(LIBFT_D) -lft -o $(CLIENT)

clean:
	make -C $(LIBFT_D) clean
	rm -f $(SERVER) $(CLIENT)

fclean: clean
	make -C $(LIBFT_D) fclean

re: fclean all

.PHONY: all clean fclean re

