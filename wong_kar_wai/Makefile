# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/05 19:28:49 by tcharlat          #+#    #+#              #
#    Updated: 2015/03/01 21:26:04 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re libft norme

CC = 	gcc
F =		-Wall -Wextra -Werror -g
NAME = 	game_2048
IDIR =	includes/
ODIR =	bin/
I =		-I $(IDIR)
I +=	-I ./libft/includes/
L =		-L ./libft/ -lft
L +=	-L /usr/lib -lncurses
EXT =	Makefile
EXT +=	libft/libft.a
EXT +=	$(IDIR)$(NAME).h
EXT +=	$(IDIR)display.h
EXT +=	$(IDIR)enum.h
EXT +=	$(IDIR)fonts.h
EXT +=	$(IDIR)game.h
EXT +=	$(IDIR)init.h
EXT +=	$(IDIR)input.h
EXT +=	$(IDIR)macros.h
EXT +=	$(IDIR)struct.h

# **************************************************************************** #
# Main                                                                         #
# **************************************************************************** #

SRC =	$(NAME).c
SRC +=	error.c

# **************************************************************************** #
# Initialization                                                               #
# **************************************************************************** #

SRC +=	init.c
SRC +=	init_ncurse.c
SRC +=	init_game.c
SRC +=	init_canvas.c
SRC +=	init_signals.c
SRC +=	init_fonts.c
SRC +=	colors.c

# **************************************************************************** #
# Display management                                                           #
# **************************************************************************** #

SRC +=	display.c

# **************************************************************************** #
# Input                                                                        #
# **************************************************************************** #

SRC +=	input.c
# SRC +=	move.c
# SRC +=	arrows.c

# **************************************************************************** #
# Game                                                                         #
# **************************************************************************** #

SRC +=	game.c
SRC +=	victory.c
SRC +=	input_is_valid.c
SRC +=	push_line.c

# **************************************************************************** #
# MAKE RULES                                                                   #
# **************************************************************************** #

O = $(addprefix $(ODIR), $(SRC:.c=.o))
vpath %.c srcs/:srcs/init/:srcs/display/:srcs/input/:srcs/game/:srcs/error/

all: libft $(NAME)

$(NAME): $(O) $(EXT)
	@echo "-> Creating $(NAME)..."
	@$(CC) $(F) $(I) -o $@ $(O) $(L)

$(ODIR)%.o: %.c $(EXT)
	@echo "-> Compiling $<..."
	@$(CC) $(F) -c -o $@ $< $(I)

$(O): | ./bin

./bin:
	@mkdir $(ODIR)

libft:
	@make -C libft

libft/libft.a:
	@make -C libft

clean:
	@make clean -C libft
	@echo "-> Cleaning $(NAME) object files..."
	@rm -rf $(ODIR)

fclean: clean
	@make fclean -C libft
	@echo "-> Cleaning $(NAME)..."
	@rm -f $(NAME)

re: fclean all

debug: CC = cc
debug: F += --analyze
debug: re

libftnorme:
	@make norme -C libft

norme:
	@norminette

