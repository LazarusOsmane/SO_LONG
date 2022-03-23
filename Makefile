# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lazarus <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 19:26:01 by lazarus           #+#    #+#              #
#    Updated: 2022/03/20 22:28:44 by lazarus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c parse.c memoire.c
OBJ = ${SRC:%.c=%.o}
CFLAG = -g3 -Wall -Wextra -Werror
UNAME := $(shell uname)

all: so_long

ifeq ($(UNAME), Linux)
so_long: $(OBJ)
	gcc $(CFLAG) $(OBJ) -o $@ libft/libft.a minilibx-linux/libmlx_Linux.a -lXext -lX11 -I./minilibx_linux/ 

%.o: %.c
		cd libft/ && make && cd ..
		cd minilibx-linux && make && cd ../
		gcc $(CFLAG) -c $^ -o $@
endif

ifeq ($(UNAME), Darwin)
so_long: $(OBJ)
	#$(CC) $(CFLAG) $(OBJ) minilibx_opengl_20191021/libmlx.a -lreadline -o $@  -lmlx -framework OpenGL -framework AppKit  -I./minilibx_opengl_20191021/ 
	$(CC) $(CFLAG) $(OBJ) libft/libft.a minilibx_opengl_20191021/libmlx.a  -o $@ -framework OpenGL -framework AppKit  -I./minilibx_opengl_20191021/ 

%.o: %.c
	cd libft/ && make && cd ..
	cd minilibx_opengl_20191021/ && make && cd ../
	$(CC) $(CFLAG) -c $< -o $@
endif

clean: 
		rm *.o

fclean:
		rm *.o so_long

re: fclean all
		cd libft && make re && cd ..

.PHONY: all fclean clean re
