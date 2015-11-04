# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/17 18:41:47 by pciavald          #+#    #+#              #
#    Updated: 2014/06/26 17:45:40 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in
C		=	cc
F		=	-g -Wall -Wextra -Werror

SDIR	=	./src/
IDIR	=	./inc/
ODIR	=	./obj/

I		=	-I $(IDIR)
I		+=	-I ./libft/includes/
L		=	-L ./libft/
LIB		=	-lft

EXT		=	Makefile
EXT		+=	$(IDIR)lem_in.h

SRC		=	main.c \
			file.c \
			lines.c \
			add.c \
			ants.c \
			update.c \
			start.c \
			choose.c \
			helper.c
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

gui:
	@echo "getting lib..."
	@curl -O 'https://dl.dropboxusercontent.com/u/53010531/Public/networkx.tar'\
		--progress-bar
	@echo "extracting lib..."
	@tar -xf networkx.tar
	@echo "removing archive...\nDone."
	@rm -rf networkx.tar

clean:
	@echo "cleaning object files..."
	@rm -rf $(ODIR)

fclean: clean
	@echo "cleaning $(NAME) binary..."
	@rm -rf $(NAME)
	@echo "removing graphic library..."
	rm -rf networkx

launch: all
	@echo "launching."
	@./$(NAME) < map/1.map

launchg: all
	@echo "launching graphics."
	@python gui.py map/1.map

debug: all
	@echo "entering debug mode."
	@gdb -q $(NAME)

lib:
	@echo "recompiling libft..."
	@make -C libft

re: fclean lib all

.PHONY: all clean fclean re
