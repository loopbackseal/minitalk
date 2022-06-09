# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 18:02:54 by yohwang           #+#    #+#              #
#    Updated: 2022/06/09 18:14:06 by yohwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

NAME = server \
	   client
SRCS =	server.c print_func.c \
		client.c print_func.c atoi_func.c
OBJS = $(SRCS:%.c=%.o)

INCLUDES = -I minitalk.h

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

server: server.o print_func.o
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

client: client.o print_func.o atoi_func.o
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
