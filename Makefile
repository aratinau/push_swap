# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/21 15:30:57 by aratinau          #+#    #+#              #
#    Updated: 2015/06/23 22:22:35 by aratinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = dlist_delete.c \
	  dlist_display.c \
	  dlist_insert.c \
	  swap_operations.c \
	  misc.c \
	  push_swap.c \
	  error.c \
	  main.c \
	  couleurs.c

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

$(NAME):$(OBJ)
	make -C includes/
	$(CC) $(CFLAGS) $^ -o $(NAME) \
	includes/libft.a

all: $(NAME)

%.o:%.c
	$(CC) -c $(SRC) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
