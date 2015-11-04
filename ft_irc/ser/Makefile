# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/04 11:09:53 by pciavald          #+#    #+#              #
#    Updated: 2014/05/25 21:25:26 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	serveur
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
EXT		+=	$(IDIR)bircd.h

SRC		=	check_fd.c \
			clean_fd.c \
			client_read.c \
			client_write.c \
			do_select.c \
			get_opt.c \
			init_env.c \
			init_fd.c \
			main.c \
			main_loop.c \
			srv_accept.c \
			srv_create.c \
			server_info.c \
			parse.c \
			basic_functions.c \
			helper.c \
			x.c

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
