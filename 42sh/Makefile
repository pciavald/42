# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/04 11:09:53 by pciavald          #+#    #+#              #
#    Updated: 2014/03/27 20:50:00 by mfebvay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	42sh
C		=	cc
F		=	-O0 -g3 -Wall -Wextra -Werror

SDIR	=	./sources/
IDIR	=	./includes/
ODIR	=	./objects/

HDIR	=	helpers/
PDIR	=	prompt/
BDIR	=	builtin/
LDIR	=	lexer/
ADIR	=	parser/
EDIR	=	executer/

LIBFT	=	./libft/libft.a

I		=	-I $(IDIR)
I		+=	-I ./libft/includes/
L		=	-L ./libft/
L		+=	-L /usr/lib
LIB		=	-lft -ltermcap

EXT		+=	Makefile
EXT		+=	$(IDIR)builtin.h
EXT		+=	$(IDIR)macro.h
EXT		+=	$(IDIR)proto.h
EXT		+=	$(IDIR)struct.h

SRC		=	main.c \
			init.c \
			termcaps.c \
			$(HDIR)quit.c \
			$(HDIR)signals.c \
			$(HDIR)split.c \
			$(HDIR)error.c \
			$(HDIR)free.c \
			$(PDIR)prompt.c \
			$(PDIR)read.c \
			$(PDIR)arrows.c \
			$(PDIR)ctrl.c \
			$(PDIR)ascii.c \
			$(PDIR)delete.c \
			$(PDIR)enter.c \
			$(PDIR)keys.c \
			$(PDIR)nl_handler.c \
			$(PDIR)freefunc.c \
			$(PDIR)tools.c \
			$(LDIR)lexer.c \
			$(LDIR)separators.c \
			$(LDIR)logic.c \
			$(LDIR)other.c \
			$(LDIR)redir.c \
			$(LDIR)blanks.c \
			$(LDIR)tools.c \
			$(ADIR)parser.c \
			$(ADIR)parse_redir.c \
			$(EDIR)executer.c \
			$(EDIR)exec_inf.c \
			$(EDIR)exec_pipe.c \
			$(EDIR)exec_separators.c \
			$(EDIR)exec_simple.c \
			$(EDIR)exec_sup.c \
			$(BDIR)builtin.c \
			$(BDIR)dup_env.c \
			$(BDIR)put_env.c \
			$(BDIR)new_env.c \
			$(BDIR)set_envline.c \
			$(BDIR)setenv.c \
			$(BDIR)getenv.c \
			$(BDIR)unsetenv.c \
			$(BDIR)env.c \
			$(BDIR)echo.c \
			$(BDIR)cd.c \
			$(BDIR)get_path.c \
			$(BDIR)path_simplifier.c \
			$(BDIR)exit.c

S		=	$(addprefix $(SDIR), $(SRC))

OBJ		=	$(SRC:.c=.o)
O		=	$(addprefix $(ODIR), $(OBJ))

all: $(NAME)

$(NAME): lib $(O) $(EXT)
	@echo "creating $(NAME)..."
	@$(C) $(F) $(I) $(L) -o $@ $(O) $(LIB)
	@echo "done."

$(ODIR)%.o: $(SDIR)%.c $(EXT)
	@echo "compiling $<..."
	@$(C) $(F) -c -o $@ $< $(I)

$(O): | $(ODIR)
$(ODIR):
	@mkdir $(ODIR)
	@mkdir $(ODIR)$(HDIR)
	@mkdir $(ODIR)$(PDIR)
	@mkdir $(ODIR)$(BDIR)
	@mkdir $(ODIR)$(LDIR)
	@mkdir $(ODIR)$(ADIR)
	@mkdir $(ODIR)$(EDIR)

clean:
	@echo "cleaning object files..."
	@rm -rf $(ODIR)

fclean: clean
	@echo "cleaning $(NAME) binary..."
	@rm -rf $(NAME)
	@echo "cleaning libft..."
	@make fclean -C libft

launch: all
	@echo "launching."
	@./$(NAME)

gdb: all
	@echo "entering debug mode."
	@sudo gdb -q $(NAME)

lldb: all
	@echo "entering debug mode."
	@lldb $(NAME)

lib:
	@echo "compiling libft..."
	@make -C libft

re: fclean lib all

.PHONY: all clean fclean re
