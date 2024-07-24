# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 13:07:29 by eda-mata          #+#    #+#              #
#    Updated: 2024/07/22 13:10:13 by eda-mata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = cc
CLIENT = client
SERVER = server
SRCS = client.c server.c
OBJS = $(SRCS:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): client.o
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): server.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: clean fclean re


