# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: engooh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 17:55:57 by engooh            #+#    #+#              #
#    Updated: 2021/12/17 10:25:01 by engooh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_printf_utils.c

OBJ = ${SRC:.c=.o}

NAME = libftprintf.a

RM  = rm -f

FLAG = -Wall -Werror -Wextra

all: ${NAME}

%.o: %.c
	gcc ${FLAG} -c $< -o $@ -I ./

${NAME}: ${OBJ}
	ar rcs $@ $^
	ranlib $@
clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all fclean clean re
