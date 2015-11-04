# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/23 17:22:42 by pciavald          #+#    #+#              #
#    Updated: 2014/05/25 15:54:09 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

MAIN_TEST = https://raw.github.com/nirahiel/Maintest/master/libft/main.c

NAME	=	libft.a

CC		=	cc
FLAGS	=	-g -Wall -Wextra -Werror

IDIR	=	./includes/
ODIR	=	./obj/

I		=	-I $(IDIR)

EXT		=	Makefile
EXT		+=	$(IDIR)libft.h

SRC		=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_isprintnstr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strclr.c \
			ft_strdel.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strjoindel.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_printsplit.c \
			ft_freesplit.c \
			ft_countsplit.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstpushback.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_strrealloc.c \
			ft_avladd.c \
			ft_avladd_rotations.c \
			ft_avldel.c \
			ft_avlheight.c \
			ft_avliter_inorder.c \
			ft_avliter_inorderrev.c \
			ft_avlnew.c \
			ft_lstrev.c \
			ft_lstsize.c \
			ft_match.c \
			get_next_line.c

S		=	$(addprefix $(SDIR), $(SRC))

OBJ		=	$(SRC:.c=.o)
O		=	$(addprefix $(ODIR), $(OBJ))

all: $(NAME)

creating:
	@echo " - compiling sources\c"

$(NAME): creating $(O) $(EXT)
	@echo "\n - Creating library..."
	@ar rc $(NAME) $(O)
	@echo " - Optimizing..."
	@ranlib $(NAME)
	@echo "libft done."


$(ODIR)%.o: $(SDIR)%.c $(EXT)
	@echo ".\c"
	@$(CC) $(FLAGS) -c -o $@ $< $(I)

$(O): | $(ODIR)
$(ODIR):
	@mkdir $(ODIR)

clean:
	@echo "cleaning object files..."
	@rm -rf $(ODIR)

fclean: clean
	@echo "cleaning $(NAME) binary..."
	@rm -rf $(NAME)

re: fclean all
