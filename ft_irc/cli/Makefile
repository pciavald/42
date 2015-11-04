# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/04 11:09:53 by pciavald          #+#    #+#              #
#    Updated: 2014/05/25 06:36:38 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	client
C		=	cc
F		=	-O0 -g3 -Wall -Wextra -Werror

SDIR	=	./src/
IDIR	=	./inc/
ODIR	=	./obj/

I		=	-I $(IDIR)
I		+=	-I ../libft/includes
L		=	-L ../libft
LIB		=	-lft

EXT		+=	Makefile
EXT		+=	$(IDIR)client.h

SRC		=	main.c \
			init.c \
			join.c \
			helper.c \
			client_read.c \
			client_write.c \
			do_select.c

S		=	$(addprefix $(SDIR), $(SRC))

OBJ		=	$(SRC:.c=.o)
O		=	$(addprefix $(ODIR), $(OBJ))

all: $(NAME)

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

launch: all
	@echo "launching."
	@./$(NAME) 4242

gdb: all
	@echo "entering debug mode."
	@sudo gdb -q --args $(NAME) 4242

lldb: all
	@echo "entering debug mode."
	@lldb $(NAME)

re: fclean all

.PHONY: all clean fclean re
