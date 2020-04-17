# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 17:34:41 by andrejskobe       #+#    #+#              #
#    Updated: 2020/04/11 17:37:30 by andrejskobe      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar

CFLAGS		=	-Wall -Wextra -Werror -fPIC

VM_FILES	=	check_cards.c	check.c		cursor.c		execute_op.c	\
				get_arg_value.c	get_bytes.c	op.c			prepair_game.c	\
				set_bytes.c		vm.c										\

OP_FILES	=	add.c			aff.c		and.c			fork.c			\
				ld.c			ldi.c		lfork.c			live.c			\
				lld.c			lldi.c		or.c			st.c			\
				sti.c			sub.c		xor.c			zjmp.c			\

CHECK_FILES	=	check_content.c	flag_init.c	read_player.c	valid_check.c	\
				write_error.c												\

DIR_SRC		=	./src

DIR_CHFILES	=	$(DIR_SRC)/file_validation

DIR_OPFILES	=	$(DIR_SRC)/operations

OBJECTS_DIR	=	objects

P_FILES		=	$(VM_FILES:.c=.o) $(OP_FILES:.c=.o) $(CHECK_FILES:.c=.o)

PATH_O		=	$(addprefix $(OBJECTS_DIR)/, $(P_FILES))

LIB_DIR		=	libft/
LIBFT		=	$(LIB_DIR)libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(PATH_O)
	@mkdir -p $(OBJECTS_DIR)
	@make -C $(LIB_DIR)
	@gcc -fPIC -o corewar $(PATH_O) $(LIBFT)
	@echo "Corewar compiled"

$(OBJECTS_DIR)/%.o: $(DIR_CHFILES)/%.c
	@mkdir -p $(OBJECTS_DIR)
	@echo "COMPILING" $<
	@gcc $(CFLAGS) -fPIC -c $< -o $@

$(OBJECTS_DIR)/%.o: $(DIR_OPFILES)/%.c
	@mkdir -p $(OBJECTS_DIR)
	@echo "COMPILING" $<
	@gcc $(CFLAGS) -fPIC -c $< -o $@

$(OBJECTS_DIR)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(OBJECTS_DIR)
	@echo "COMPILING" $<
	@gcc $(CFLAGS) -fPIC -c $< -o $@

clean:
			@rm -rf $(OBJECTS_DIR)
			@echo "$(RED)deleting corewar object files...$(NC) ✔"
			@make -C $(LIB_DIR) clean

fclean:		clean
			@echo "$(RED)deleting corewar executable file...$(NC) ✔"
			@rm -rf $(NAME)

re:			fclean all
