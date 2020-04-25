# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msabre <msabre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 17:34:41 by andrejskobe       #+#    #+#              #
#    Updated: 2020/04/25 12:19:25 by msabre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COREWAR		=	corewar

ASM			=	asm

CFLAGS		=	-Wall -Wextra -Werror -fPIC

VM_FILES	=	check_cards.c	check.c		cursor.c		execute_op.c	\
				get_arg_value.c	get_bytes.c	op.c			prepair_game.c	\
				set_bytes.c		vm.c		arena_output.c					\

OP_FILES	=	add.c			aff.c		and.c			fork.c			\
				ld.c			ldi.c		lfork.c			live.c			\
				lld.c			lldi.c		or.c			st.c			\
				sti.c			sub.c		xor.c			zjmp.c			\

CHECK_FILES	=	check_content.c	flag_init.c	read_player.c	valid_check.c	\
				write_error.c												\

ASM_FILES	=	asm.c init_ssl.c including_magic.c write_error.c			\
				compare.c compare_2.c init_exec.c skip_probel.c				\
				is_whitespace.c no_comment.c add_list.c is_limit.c			\
				connecting_people.c is_registr.c add_label.c take_label.c cnl.c \
				take_arg1.c no_separator.c take_arg2.c inst_aff.c			\
				inst_lfork.c inst_fork.c inst_live.c inst_zjmp.c			\
				inst_lld.c inst_ld.c inst_st.c inst_add.c					\
				take_arg3.c inst_sub.c inst_and.c inst_or.c					\
				inst_xor.c inst_ldi.c inst_lldi.c inst_sti.c				\
				add_comand.c label_change.c label_search1.c label_search2.c	\
				label_search3.c skolkovo.c check_name.c check_comment.c		\
				arg_add.c kod_type_arg.c add_kta.c free_label.c free_exec.c	\
				free_tfile.c line_to_write.c including_size.c name_comment.c\
				rename_f.c choose_n_c.c c_data.c line_part.c				\
				order_arg.c line_to_write2.c take_opera.c take_label2.c		\
				check_comment2.c check_comment3.c check_name2.c check_name3.c\
				take_arg1_r.c take_arg1_pr.c take_arg1_d.c take_arg1_n.c	\
				take_arg1_neg.c take_arg1_dv.c take_arg1_pr_neg.c			\
				take_arg2_pr.c take_arg2_r.c take_arg2_d.c					\
				take_arg2_dv.c take_arg2_neg.c take_arg2_n.c take_arg2pr_neg.c\
				take_arg3_r.c take_arg3_pr.c take_arg3_neg.c take_arg3_d.c	\
				take_arg3_n.c take_arg3_pr_neg.c take_arg3_dv.c				\

DIR_ASM		=	src/asm

DIR_COREWAR	=	src/corewar

DIR_CHFILES	=	$(DIR_COREWAR)/file_validation

DIR_OPFILES	=	$(DIR_COREWAR)/operations

OBJECTS_DIR	=	objects

OBJ_COR_DIR	=	corewar_objects

OBJ_ASM_DIR	=	asm_objects

O_CORE		=	$(VM_FILES:.c=.o) $(OP_FILES:.c=.o) $(CHECK_FILES:.c=.o)

O_ASM		=	$(ASM_FILES:.c=.o)

COR_PATH_O	=	$(addprefix $(OBJECTS_DIR)/$(OBJ_COR_DIR)/, $(O_CORE))

ASM_PATH_O	=	$(addprefix $(OBJECTS_DIR)/$(OBJ_ASM_DIR)/, $(O_ASM))

LIB_DIR		=	libft

LIBFT		=	libft.a

LIB_PATH	=	$(LIB_DIR)/$(LIBFT)

.PHONY: all clean fclean re

all: $(LIBFT) $(OBJECTS_DIR) $(OBJ_COR_DIR) $(OBJ_ASM_DIR) $(ASM) $(COREWAR)

$(LIBFT):
	@make -C libft
	@echo "\\n\033[32;1m...libft compiled...\033[0m \\n"
	@sleep 1

$(COREWAR): $(LIBFT) $(OBJECTS_DIR) $(OBJ_COR_DIR) $(COR_PATH_O)
	@gcc $(CFLAGS) -o $(COREWAR) $(COR_PATH_O) $(LIB_PATH)
	@echo "\\n\033[32;1m...corewar compiled...\033[0m \\n"
	@sleep 1

$(ASM): $(LIBFT) $(OBJECTS_DIR) $(OBJ_ASM_DIR) $(ASM_PATH_O)
	@gcc $(CFLAGS) -o $(ASM) $(ASM_PATH_O) $(LIB_PATH)
	@echo "\\n\033[32;1m...asm compiled...\033[0m \\n"
	@sleep 1

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJ_COR_DIR):
	@mkdir -p $(OBJECTS_DIR)/$(OBJ_COR_DIR)

$(OBJ_ASM_DIR):
	@mkdir -p $(OBJECTS_DIR)/$(OBJ_ASM_DIR)

$(OBJECTS_DIR)/$(OBJ_COR_DIR)/%.o: $(DIR_CHFILES)/%.c
	@echo "compiling corewar (validation part) : " $<
	@gcc $(CFLAGS) -c $< -o $@

$(OBJECTS_DIR)/$(OBJ_COR_DIR)/%.o: $(DIR_OPFILES)/%.c
	@echo "compiling corewar (operations) : " $<
	@gcc $(CFLAGS) -c $< -o $@

$(OBJECTS_DIR)/$(OBJ_COR_DIR)/%.o: $(DIR_COREWAR)/%.c
	@echo "compiling corewar : " $<
	@gcc $(CFLAGS) -c $< -o $@

$(OBJECTS_DIR)/$(OBJ_ASM_DIR)/%.o: $(DIR_ASM)/%.c
	@echo "compiling asm : " $<
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECTS_DIR)
	@echo "\\n\033[32;1m...deleting corewar object files...\033[0m \\n"
	@echo "\\n\033[32;1m...deleting asm object files...\033[0m \\n"
	@make -C $(LIB_DIR) clean

fclean:	clean
	@rm -rf $(COREWAR)
	@rm -rf $(ASM)
	@echo "\\n\033[32;1m...deleting corewar executable file...\033[0m \\n"
	@echo "\\n\033[32;1m...deleting asm executable file...\033[0m \\n"
	@make -C $(LIB_DIR) fclean

re:			fclean all
