#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorre <fcorre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/26 19:25:11 by fcorre            #+#    #+#              #
#    Updated: 2014/06/26 20:52:40 by mfebvay          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re

FILES = main.c \
		opt.c \
		opt2.c \
		team_add.c \
		usage.c \
		init_data.c \
		init_server.c \
		srv_accept.c \
		client_read.c \
		client_write.c \
		clean_fd.c \
		error.c \
		check_fd.c \
		init_fd.c \
		cmd_handl.c \
		player_init.c \
		player_add.c \
		egg_del.c \
		gui_init.c \
		gcmd_bct.c \
		gcmd_mct.c \
		gcmd_tna.c \
		gcmd_msz.c \
		gcmd_sgt.c \
		gcmd_pin.c \
		gcmd_sst.c \
		gcmd_plv.c \
		gui_pnw.c \
		gui_plist.c \
		gui_enw.c \
		gui_elist.c \
		gui_ppo.c \
		gcmd_ppo.c \
		gui_plv.c \
		gui_bct.c \
		gui_msz.c \
		gui_mct.c \
		gui_pex.c \
		gui_sgt.c \
		gui_tna.c \
		ccmd_invent.c \
		action_add.c \
		free_split.c \
		ft_itoa.c \
		team_join.c \
		split_dup.c \
		strsplit.c \
		time_add.c \
		strsub.c \
		t_cmd.c \
		ccmd_bcast.c \
		ccmd_drop.c \
		ccmd_fork.c \
		ccmd_forward.c \
		ccmd_incant.c \
		ccmd_left.c \
		ccmd_look.c \
		ccmd_look_see.c \
		ccmd_look_concat.c \
		ccmd_max.c \
		ccmd_push.c \
		ccmd_right.c \
		ccmd_take.c \
		get_square.c \
		routine_action.c \
		routine_food.c \
		action_delfirst.c \
		time_diff.c \
		gui_broadcast.c \
		gui_pgt.c \
		gui_pin.c \
		gui_pdr.c \
		gui_ebo.c \
		mod.c \
		gui_pfk.c \
		gui_edi.c \
		gui_pdi.c \
		player_del.c \
		init_spell_tab.c \
		gui_pic.c \
		routine_spell.c \
		gui_pie.c \
		spell_del.c \
		routine_egg.c \
		gui_eht.c \
		gui_pbc.c \
		split_join.c \
		routine_spell_disperse1.c \
		routine_spell_disperse2.c \
		spell_check.c \
		gui_sbp.c \
		get_player.c \
		gui_suc.c \
		t_gcmd.c \
		win_check.c \
		gui_seg.c \
		quit_game.c \
		clean_teams.c \
		team_del.c \
		clean_players.c \
		clean_eggs.c \
		clean_spells.c \
		clean_spell_tab.c \
		clean_map.c
CFLAGS = -Wall -Wextra -Werror -g0 -I ./inc
SRC = $(addprefix src/, $(FILES))
OBJ = $(SRC:src/%.c=obj/%.o)
NAME = serveur
CC = gcc

all: $(NAME)

$(NAME): $(OBJ) ./inc/server.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

obj/%.o: src/%.c
	@mkdir -p obj/
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

launch: all
	./serveur -p 4242 -x 20 -y 20 -n lol bop -c 10 -t 10

debug: all
	gdb -q --args serveur -p 4242 -x 20 -y 20 -n lol dop -c 1 -t 50

re: fclean all
