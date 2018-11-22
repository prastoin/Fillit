# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prastoin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 15:53:54 by prastoin          #+#    #+#              #
#    Updated: 2018/11/21 16:31:04 by prastoin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 

PT_C = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	   ft_isprint.c ft_itoa.c ft_memccpy.c ft_memalloc.c ft_memchr.c \
	   ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	   ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	   ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strclr.c \
	   ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	   ft_striter.c ft_striteri.c ft_strjoin.c ft_strlen.c \
	   ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	   ft_strnstr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c \
	   ft_strtrim.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strlcat.c \
	   ft_strmap.c ft_strmapi.c ft_strrchr.c ft_lstadd.c ft_lstdel.c \
	   ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	   ft_iterative_factorial.c ft_sqrt.c ft_strcapitalize.c \
	   ft_str_is_uppercase.c ft_str_is_alpha.c ft_str_is_lowercase.c \
	   ft_str_is_numeric.c


PT_O = $(PT_C:.c=.o)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	gcc $(FLAG) -c $(PT_C) -I ./includes
	ar rc $(NAME) $(PT_O)
	ranlib $(NAME)

clean :
	rm -rf $(PT_O)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
