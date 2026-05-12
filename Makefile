# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/13 00:24:51 by kaichan           #+#    #+#              #
#    Updated: 2026/05/13 00:26:03 by kaichan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CLIENT = client.c

SERVER = server.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

# remove and force remove
RM = rm -f

SRCS = ${PART1} ${PART2}

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

# no need for -I. include path header in same folder.
# derived from source .c
.c:.o
		${CC} ${CFLAG} -c $< -o ${<: .c=.o}

# ${NAME}: ${OBJS} Runs only if .o files changed or ${NAME} missing.
${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

# bonus: Always runs, ignores whether ${NAME} exists.
bonus:	${OBJS} ${BONUS_OBJS}
		ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

# just clean .o
clean:
	${RM} ${OBJS} ${BONUS_OBJS}

# cleans all including .o and libft.a
fclean: clean
	${RM} ${NAME}

# rebuild the library cleans then remakes
re: fclean all

