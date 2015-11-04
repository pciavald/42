# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 11:16:59 by pciavald          #+#    #+#              #
#    Updated: 2014/01/19 20:25:47 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all $(NAME) clean fclean re

NAME = wolf3d
SRCS = main_wolf3d.c \
	   functions.c \
	   draw.c \
	   init_e.c \
	   find_wall.c \
	   key.c \
	   effect.c

OBJ  = $(SRCS:.c=.o)
HEAD = header_wolf3d.h

FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -L/usr/X11/lib/ -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -g -o $@ $^ -I /usr/X11/include/ $(FLAGS_MLX)
	@echo "$(NAME) : done."

%.o:%.c
	@gcc $(FLAGS) -c -o $@ $< -I /usr/X11/include/

clean:
	@rm -f $(OBJ)
	@echo ".o     : deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) : deleted."

re: fclean all

