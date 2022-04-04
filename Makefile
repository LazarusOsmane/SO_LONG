# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lazarus <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 19:26:01 by lazarus           #+#    #+#              #
#    Updated: 2022/04/04 13:54:39 by engooh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c parse.c memoire.c games.c draw.c move.c
OBJ = ${SRC:%.c=%.o}
CFLAG = -Wall -Wextra -Werror
UNAME := $(shell uname)

all: so_long

assan: so_long_assan 

ifeq ($(UNAME), Linux)
so_long: $(OBJ)
	gcc $(CFLAG) $(OBJ) -o $@ libft/libft.a Printf/libftprintf.a minilibx-linux/libmlx_Linux.a -lXext -lX11 -I./minilibx_linux/ 

so_long_assan: $(OBJ)
	gcc $(CFLAG) -fsanitize=address -static-libasan $(OBJ) -o $@ libft/libft.a minilibx-linux/libmlx_Linux.a -lXext -lX11 -I./minilibx_linux/ 

%.o: %.c
	cd Printf/ && make && cd ..
	cd libft/ && make && cd ..
	cd minilibx-linux && make && cd ..
	gcc $(CFLAG) -c $^ -o $@
endif

ifeq ($(UNAME), Darwin)
so_long: $(OBJ)
	$(CC) $(CFLAG) $(OBJ) libft/libft.a minilibx_opengl_20191021/libmlx.a  Printf/libftprintf.a -o $@ -framework OpenGL -framework AppKit  -I./minilibx_opengl_20191021/ 

%.o: %.c
	cd Printf/ && make && cd ..
	cd libft/ && make && cd ..
	cd minilibx_opengl_20191021/ && make && cd ..
	$(CC) $(CFLAG) -c $< -o $@
endif

clean: 
	cd Printf/ && make clean && cd ..
	cd libft/ && make clean && cd ..
	rm *.o

fclean:
	cd Printf/ && make fclean && cd ..
	cd libft/ && make fclean && cd ..
	rm *.o so_long

re: fclean all

.PHONY: all fclean clean re
