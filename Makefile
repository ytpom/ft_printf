# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 22:23:44 by jphilip-          #+#    #+#              #
#    Updated: 2019/04/07 17:35:11 by jphilip-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC = includes
SRC = ft_printf.c
LIB = libft

OBJ = $(SRC:.c=.o)

CC = gcc
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	cp $(LIB)/$(LIB).a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAG) -I $(INC) -c $< -o $@

clean:
	make clean -C $(LIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all

test:
	$(CC) $(FLAG) -I $(INC) -L . -lftprintf main.c -o test

clear:
	rm -f $(NAME)
	rm -f ./test

full: clear all test

cls: fclean clear
