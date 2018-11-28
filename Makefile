# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 16:50:34 by amerrouc          #+#    #+#              #
#    Updated: 2018/11/28 14:31:43 by amerrouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c verif.c abc.c mv_piece.c algo.c put_piece.c rm_piece.c	\
	  size_piece.c ft_sqrt_close.c reading.c solver.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIB = libft/libft.a

INC = -I./libft/

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAG) $(LIB) $(INC) $(OBJ) -o $(NAME)

$(LIB):
	make -C libft/ fclean
	make -C ./libft/

%.o: %.c
	gcc -g $(FLAG) $(INC) -o $@ -c $< 

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
