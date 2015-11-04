# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/22 14:01:02 by pciavald          #+#    #+#              #
#    Updated: 2014/05/15 19:08:46 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

EXT		=	Makefile

GREEN	=	\x1B[0;32m
NC		=	\x1B[0m

all: lib

lib:
	@echo "$(GREEN)[lanching make for libft]$(NC)"
	@make -C libft
	@echo "$(GREEN)[lanching make for server]$(NC)"
	@make -C ser
	@echo "$(GREEN)[lanching make for client]$(NC)"
	@make -C cli
	@echo "$(GREEN)[moving files in place]$(NC)"
	@mv cli/client .
	@mv ser/serveur .
	@echo "done."

clean:
	@echo "$(GREEN)[lanching clean for server]$(NC)"
	@make clean -C ser
	@echo "$(GREEN)[lanching clean for client]$(NC)"
	@make clean -C cli
	@echo "$(GREEN)[lanching clean for libft]$(NC)"
	@make clean -C libft

fclean:
	@echo "$(GREEN)[lanching fclean for server]$(NC)"
	@make fclean -C ser
	@echo "$(GREEN)[cleaning moved server]$(NC)"
	@rm serveur
	@echo "$(GREEN)[lanching fclean for client]$(NC)"
	@make fclean -C cli
	@echo "$(GREEN)[cleaning moved client]$(NC)"
	@rm client
	@echo "$(GREEN)[lanching fclean for libft]$(NC)"
	@make fclean -C libft

re: fclean all
