# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 16:50:34 by amerrouc          #+#    #+#              #
#    Updated: 2018/11/22 14:24:02 by amerrouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c verif.c abc.c mv_piece.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIB = ./libft/libft.a

INC = -I./includes/ -I./libft/includes/

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAG) $(LIB) $(INC) $(OBJ) -o $(NAME)

$(LIB):
	make -C libft/ fclean
	make -C ./libft/

%.o: %.c
	gcc $(FLAG) $(INC) -o $@ -c $< 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
