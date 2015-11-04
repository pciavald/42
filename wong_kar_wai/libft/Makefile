# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/09 03:55:56 by tcharlat          #+#    #+#              #
#    Updated: 2014/02/23 14:10:11 by tcharlat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

NAME =	libft.a
CC =	gcc
FLAGS =	-Wall -Werror -Wextra -O3 -g
ODIR =	bin/
IDIR =	includes/
SRC =	  
OBJ =	$(SRC:.c=.o)
EXT =	$(IDIR)$(NAME:.a=.h)
EXT +=	$(IDIR)ft_char.h
EXT +=	$(IDIR)ft_integer.h
EXT +=	$(IDIR)ft_mem.h
EXT +=	$(IDIR)ft_put.h
EXT +=	$(IDIR)ft_str.h
EXT +=	$(IDIR)ft_strarray.h
EXT +=	$(IDIR)ft_strlst.h
EXT +=	$(IDIR)get_next_line.h
EXT +=	$(IDIR)ft_dlist.h
EXT +=	$(IDIR)ft_dlist_de.h
EXT +=	$(IDIR)ft_dlist_buffer.h
EXT +=	$(IDIR)ft_slist_circ.h
EXT +=	$(IDIR)ft_slist_free.h
EXT +=	$(IDIR)ft_slist_queue.h
EXT +=	$(IDIR)ft_slist_stack.h
EXT +=	$(IDIR)ft_getopt.h
EXT +=	Makefile

# **************************************************************************** #
# char                                                                         #
# **************************************************************************** #
SRC +=	ft_isalpha.c
SRC +=	ft_isdigit.c
SRC +=	ft_isalnum.c
SRC +=	ft_isascii.c
SRC +=	ft_isprint.c
SRC +=	ft_toupper.c
SRC +=	ft_tolower.c
# **************************************************************************** #
# Get Next Line                                                                #
# **************************************************************************** #
SRC +=	get_next_line.c
# **************************************************************************** #
# mem                                                                          #
# **************************************************************************** #
SRC +=	ft_memset.c
SRC +=	ft_bzero.c
SRC +=	ft_memcpy.c
SRC +=	ft_memccpy.c
SRC +=	ft_memmove.c
SRC +=	ft_memchr.c
SRC +=	ft_memcmp.c

SRC +=	ft_memalloc.c
SRC +=	ft_memdel.c
# **************************************************************************** #
# put                                                                          #
# **************************************************************************** #
SRC +=	ft_putchar.c
SRC +=	ft_putchar_fd.c
SRC +=	ft_putendl.c
SRC +=	ft_putendl_fd.c
SRC +=	ft_putnbr.c
SRC +=	ft_putnbr_fd.c
SRC +=	ft_putstr.c
SRC +=	ft_putstr_fd.c
# **************************************************************************** #
# str                                                                          #
# **************************************************************************** #
SRC +=	ft_strlen.c
SRC +=	ft_strdup.c
SRC +=	ft_strcpy.c
SRC +=	ft_strncpy.c
SRC +=	ft_strcat.c
SRC +=	ft_strncat.c
SRC +=	ft_strlcat.c
SRC +=	ft_strchr.c
SRC +=	ft_strrchr.c
SRC +=	ft_strstr.c
SRC +=	ft_strnstr.c
SRC +=	ft_strcmp.c
SRC +=	ft_strncmp.c

SRC +=	ft_strnew.c
SRC +=	ft_strdel.c
SRC +=	ft_strclr.c
SRC +=	ft_striter.c
SRC +=	ft_striteri.c
SRC +=	ft_strmap.c
SRC +=	ft_strmapi.c
SRC +=	ft_strequ.c
SRC +=	ft_strnequ.c
SRC +=	ft_strsub.c
SRC +=	ft_strjoin.c
SRC +=	ft_strtrim.c
SRC +=	ft_strsplit.c
SRC +=	ft_strndup.c
# **************************************************************************** #
# strlst                                                                       #
# **************************************************************************** #
SRC +=	ft_lsttoarray.c
SRC +=	ft_arraytolst.c
SRC +=	ft_freestrlst.c
# **************************************************************************** #
# strarray                                                                     #
# **************************************************************************** #
STR +=	ft_freearray.c
STR +=	ft_arraylen.c
STR +=	ft_arraydup.c
# **************************************************************************** #
# integer                                                                      #
# **************************************************************************** #
SRC +=	ft_atoi.c
SRC +=	ft_itoa.c
# **************************************************************************** #
# dlists                                                                       #
# **************************************************************************** #
SRC +=	ft_dlist_add.c
SRC +=	ft_dlist_buffer_set.c
SRC +=	ft_dlist_de_buffer_set.c
SRC +=	ft_dlist_de_init_head.c
SRC +=	ft_dlist_de_pop.c
SRC +=	ft_dlist_de_push.c
SRC +=	ft_dlist_malloc.c
SRC +=	ft_dlist_remove.c
# **************************************************************************** #
# slists                                                                       #
# **************************************************************************** #
SRC +=	ft_slist_add.c
SRC +=	ft_slist_malloc.c
SRC +=	ft_slist_remove.c
SRC +=	ft_slist_circ.c
SRC +=	ft_slist_queue.c
SRC +=	ft_slist_stack.c
SRC +=	ft_slist_free.c
# **************************************************************************** #
# options                                                                      #
# **************************************************************************** #
SRC += ft_getopt.c
O =		$(addprefix $(ODIR), $(OBJ))
vpath %.c srcs/:srcs/char/:srcs/get_next_line/:srcs/mem/:srcs/put/:srcs/str/:srcs/strlst/:srcs/strarray/:srcs/integer/:srcs/dlist/:srcs/slist/:srcs/getopt/

all: $(NAME)

norme:
	@echo "libft Norme checks"
	@norminette $(S)

$(NAME): $(O) $(EXT)
	@echo "-> Creating $(NAME)..."
	@ar rc $(NAME) $(O)
	@echo "-> Optimising $(NAME)..."
	@ranlib $(NAME)
	@echo "-> Done !"

$(ODIR)%.o: %.c $(EXT)
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -I$(IDIR) -c $< -o $@

$(O): | ./bin

./bin:
	@mkdir $(ODIR)

clean:
	@echo "-> Cleaning libft object files..."
	@/bin/rm -rf $(ODIR)

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@/bin/rm -f $(NAME)

re: fclean all
