#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorre <fcorre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/26 19:25:11 by fcorre            #+#    #+#              #
#    Updated: 2014/06/26 22:24:43 by mfebvay          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re serveur gfx

all: serveur client gfx

serveur:
	make -C serveur/

client:
	@echo client not implemented

gfx:
	@echo please launch gui manually

clean:
	make -C serveur/ clean
	make -C gui/ clean

fclean:
	make -C serveur/ fclean
	make -C gui/ fclean

re: fclean all
