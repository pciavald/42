# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/04 11:09:53 by pciavald          #+#    #+#              #
#    Updated: 2014/05/17 10:28:10 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
C		=	cc
F		=	-O0 -g3 -Wall -Wextra -Werror

SDIR	=	./src/
IDIR	=	./inc/
ODIR	=	./obj/

I		=	-I $(IDIR)
I		+=	-I libft/includes
L		=	-L libft
LIB		=	-lft

EXT		+=	Makefile
EXT		+=	$(IDIR)push_swap.h

SRC		=	main.c \
			list.c \
			first.c \
			swap.c \
			rotate1.c \
			rotate2.c

S		=	$(addprefix $(SDIR), $(SRC))

OBJ		=	$(SRC:.c=.o)
O		=	$(addprefix $(ODIR), $(OBJ))

all: lib $(NAME)

$(NAME): $(O) $(EXT)
	@echo "creating $(NAME)..."
	@$(C) $(F) $(I) $(L) -o $@ $(O) $(LIB)
	@echo "done."

$(ODIR)%.o: $(SDIR)%.c $(EXT)
	@echo "compiling $<..."
	@$(C) $(F) -c -o $@ $< $(I)

$(O): | $(ODIR)
$(ODIR):
	@mkdir $(ODIR)

clean:
	@echo "cleaning object files..."
	@rm -rf $(ODIR)

fclean: clean
	@echo "cleaning $(NAME) binary..."
	@rm -rf $(NAME)

lib:
	@echo "making libft..."
	@make -C libft

launch: all
	@echo "launching."
	@./$(NAME) 2 1 3 6 5 8

gdb: all
	@echo "entering debug mode."
	@gdb -q --args $(NAME) 2 1 3 6 5 8

lldb: all
	@echo "entering debug mode."
	@lldb $(NAME)

re: fclean all

.PHONY: all clean fclean re
