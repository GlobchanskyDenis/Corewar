# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 12:16:02 by bsabre-c          #+#    #+#              #
#    Updated: 2020/02/15 19:12:45 by volyvar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= corewar
FLAGS		= -Wall -Wextra -Werror  -g

# directories
DIR_O		=	objects
DIR_V		=	vis
DIR_SRC		=	src
DIR_INC		=	includes
DIR_DIS		=	disasm
DIR_DIS_OP	=	disasm/disasm_operation

# files
SRC			=	vm_main.c						vm_free_exit.c				\
				vm_reader.c						vm_parse_flags_1.c			\
				vm_parse_flags_2.c				vm_extract.c				\
				vm_carriage_1.c					vm_carriage_2.c				\
				vm_initialize_all.c				vm_initialize_game.c		\
				vm_dump.c						vm_getters.c				\
				vm_get_set_bytes.c		\
				vm_war.c						vm_dump_arena.c			\
							vm_operation/null.c		\
							vm_operation/live.c		\
							vm_operation/ld.c		\
							vm_operation/st.c		\
							vm_operation/add.c		\
							vm_operation/sub.c		\
							vm_operation/and.c		\
							vm_operation/or.c		\
							vm_operation/xor.c		\
							vm_operation/zjmp.c		\
							vm_operation/sti.c		\
							vm_operation/ldi.c		\
							vm_operation/fork.c		\
							vm_operation/lld.c		\
							vm_operation/lldi.c		\
							vm_operation/lfork.c	\
							vm_operation/aff.c		

VIS			=	choose_players.c 				choose_theme.c				\
				comments.c						draw_field.c				\
				draw_letter.c					error.c						\
				free.c							game.c						\
				initial_core.c					main.c						\
				see_stat.c						theme_text.c				\
				lib/get_next_line.c  			pause.c draw_carriet.c 		\
				end_game.c 						present_winner.c			\
				titres.c						choose_players_h.c			\
				choose_players_hh.c				ft_load_players.c			\
				ft_load_players_info.c			ft_load_players_info_h.c	\
				ft_choose_players.c				ft_choose_theme.c			\
				comments_help.c					comments_help_h.c			\
				comments_help_hh.c				comments_help_hhh.c			\
				ft_new_hope.c					ft_change_comment.c			\
				comments_h.c					ft_find_owner_col.c			\
				draw_field_help.c 				ft_find_winner_file.c		\
				ft_del.c						ft_free_player_info.c		\
				present_status.c				status_change.c				\
				players_game.c					put_field.c					\
				defines.c						fon.c						\
				game_event.c					game_func.c



DIS_S		=	disasm_main.c					disasm_reader.c				\
				disasm_free_exit.c				disasm_getters.c			\
				disasm_translate.c

DIS_OP_S	=	add.c			aff.c		and.c		fork.c				\
				ld.c			ldi.c		lfork.c		live.c				\
				lld.c			lldi.c		or.c		st.c				\
				sti.c			sub.c		xor.c		zjmp.c

INC			=	op.h vis.h vm.h disasm.h
D_INC		=	$(addprefix $(DIR_INC)/,$(INC))

ASM_NAME = asm
ASM_FOLDER = asm_files/
ASM_SRC_FOLDER = $(ASM_FOLDER)srcs/
ASM_INC_FOLDER = $(ASM_FOLDER)includes/
ASM_SRC_FILES = main.c print_funcs.c ft_asm.c clean_funcs.c analize_name.c \
				init_funcs.c comments.c get_name_n_comment.c lop_funcs.c\
				reading_useful_tools.c analize_var.c read_ops.c\
				print_result.c replace_labels.c strsplitestsep.c \
				init_ops.c check_all_labels.c check_funcs.c get_funcs.c
ASM_SRC = $(addprefix $(ASM_SRC_FOLDER), $(ASM_SRC_FILES))
ASM_OBJ = $(ASM_SRC:.c=.o)
ASM_INC = -I$(ASM_INC_FOLDER)

DIS_NAME = dis_asm
DIS_SRC = 	$(addprefix $(DIR_DIS)/, $(DIS_S)) \
			$(addprefix $(DIR_DIS_OP)/, $(DIS_OP_S))
DIS_OBJ = $(DIS_SRC:.c=.o)

SRC_D		=	$(addprefix $(DIR_SRC)/,$(SRC))
# OBJ			=	$(addprefix $(DIR_O)/,$(SRC_D:.c=.o))
OBJ_V		=	$(addprefix $(DIR_V)/,$(VIS:.c=.o))
OBJ			=	$(SRC_D:.c=.o)

# TTF			=	-I./includes -L./sdl2library/ttf -lSDL2_ttf
# SDL			=	-I./includes -L./sdl2library/orig -lSDL2

# libraries
L_FT_D 		= 	./libft
L_FT_L 		= 	$(L_FT_D)/libft.a
 
AAAA 		= 		-I./frameworks/SDL2.framework/Versions/A/Headers \
					-I./frameworks/SDL2_image.framework/Versions/A/Headers \
					-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
					-I./frameworks/SDL2_mixer.framework/Versions/A/Headers \

FRAMEWORKS	=		-F./frameworks \
					-rpath ./frameworks \
					-framework SDL2 -framework SDL2_ttf -framework SDL2_image -framework SDL2_mixer

.PHONY: all clean fclean re proj

all :		$(NAME) $(ASM_NAME) $(DIS_NAME)

$(NAME) :  $(OBJ) $(OBJ_V)
			@make -sC $(L_FT_D)
			@echo "Compiling corewar"
			@gcc $(FLAGS) $(OBJ) $(OBJ_V) $(INCS) -I SDL/ $(L_FT_L) $(FRAMEWORKS) -o $(NAME)
			@echo "File $(NAME) was created successfully"

$(ASM_NAME): $(ASM_OBJ)
	@echo "Compiling asm"
	@gcc $(FLAGS) $(ASM_INC) $(ASM_OBJ) -o $(ASM_NAME) $(L_FT_L)
	@echo "File $(ASM_NAME) was created successfully"

$(DIS_NAME): $(DIS_OBJ)
	@echo "Compiling disasm"
	@gcc $(FLAGS) $(INCS) $(DIS_OBJ) -o $(DIS_NAME) $(L_FT_L)
	@echo "File $(DIS_NAME) was created successfully"

%.o: %.c
			@gcc $(FLAGS) $(INCS) -I$(DIR_INC) -I SDL/ -I$(L_FT_D) $(ASM_INC) -c $< -o $@ 

clean :
			@echo "Start cleaning"
			@make clean -sC $(L_FT_D)
			@rm -rf .DS_Store
			@rm -rf $(L_FT_D)/.DS_Store
			@rm -rf $(OBJ)
			@rm -rf $(OBJ_V)
			@/bin/rm -rf $(ASM_SRC_FOLDER)*.o
			@/bin/rm -rf $(DIR_DIS)/*.o
			@/bin/rm -rf $(DIR_DIS_OP)/*.o
			@echo "Cleaning finished"

fclean : clean
			@rm -rf $(L_FT_L)
			@rm -rf $(NAME)
			@rm -rf $(NAME).dSYM
			@rm -f $(DIS_NAME)
			@/bin/rm -f $(ASM_NAME)


re: fclean all
