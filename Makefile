#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/28 12:06:51 by grass-kw          #+#    #+#              #
#    Updated: 2014/04/24 10:34:47 by grass-kw         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

NAME = fdf

HEAD = ./libft

IFLAGS = -I . -I ./libft/includes

LIB = ./libft/libft.a

FLAGS = -Wall -Werror -Wextra -g

SRC = main.c get_next_line.c hook.c draw_img.c tool.c parser.c
#draw.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: libft $(NAME)

libft:
	make -C $(HEAD)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME) -L/usr/X11/lib -lmlx -lXext -lX11

%.o: %.c
	$(CC) $(FLAGS) $(IFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ) lem-in.dSYM


fclean: clean
	$(RM) $(NAME)
re: fclean all

gdb: $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME) -L/usr/X11/lib -lmlx -lXext -lX11
	gdb $(NAME2) -w

.PHONY: all libft clean fclean re gdb
