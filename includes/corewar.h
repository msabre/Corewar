/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:11:30 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/04/23 23:43:23 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libft/headers/libft.h"
# include "op.h"

# define ZEROS 00000000

# define SHOW_LIVES 1
# define SHOW_CYCLES 2
# define SHOW_OPERATIONS 4
# define SHOW_DEATHS 8
# define SHOW_CURSOR_MOVE 16

# define READ_ERROR "Error: Can't read this file\n"
# define HEADER_ERROR "Error: File has an invalid header\n"
# define CODE_SIZE_ERROR "Error: File has an invalide code size\n"
# define SMALL_SIZE_CODE "Error: File %s is too small to be a champion\n"
# define BIG_SIZE_CODE "Error: File has a code more than 682 bytes\n"

typedef struct			s_op
{
	char				*name;
	int					argc;
	int					argv[4];
	int					code_op;
	int					cycles;
	char				*descrip;
	int					code_args;
	int					carry_change;
	int					t_dir_size;
}						t_op;

typedef struct			s_player
{
	int					num;
	unsigned char		*name;
	unsigned char		*exe_code;
	int					code_size;
	int					len_exec;
	char				*comment;
}						t_player;

typedef struct			s_card
{
	bool				carry;
	int					num;
	int					code_op;
	int					alive_cycle;
	int					cursor;
	int					steps;
	int					cycles_to_op;
	int					regs[REG_NUMBER];
	char				args[MAX_ARGS_NUMBER];
	t_op				*op;
	t_player			*player;
	struct s_card		*next;
}						t_card;

typedef struct			s_general
{
	void				(*operations[16])(struct s_general *, t_card *);
	unsigned char		arena[MEM_SIZE];
	t_player			*last_live;
	t_player			*players[4];
	t_card				*cards;
	t_op				*op_tab;
	unsigned char		arg_types[3];
	int					reserved_nums[4];
	int					cn_octets;
	int					pl_num;
	int					show_key;
	int					aff_key;
	int					n_players;
	int					current_card_num;
	int					last_check;
	int					n_live_op;
	int					flag_v;
	int					checks_count;
	int					stop_cycle;
	int					ctd;
	int					cycles;
	int					change_ctd;
}						t_general;

void					arena_content_output(t_general *all);
void					prepare_game(t_general *all);
void					check(t_general *all);
void					read_player(int argc, char **argv, t_general *all);
int						is_flags(int i, int argc, char **argv, t_general *all);
void					valid_check(int fd, int num, t_general *all);
void					check_magic(int fd);
void					check_name(int fd, t_player *player);
void					check_zeros(int fd);
void					champ_comment(int fd, t_player *player);
void					check_champ_code(int fd, t_player *player);
void					write_error(char *str);
void					print_help();
unsigned char			get_char(unsigned char *arena, int num);
int						get_fourbytes(unsigned char *arena, int start);
int						get_twobytes(unsigned char *arena, int start);
int						next(unsigned char *arena);
void					set_byte(unsigned char *arena, unsigned char byte,
						int num);
void					set_reg(unsigned char *arena, int reg, int adress);
int						set_mem(unsigned char *arena, unsigned char *mem,
						int num, int size);
void					get_op_tab(t_general *all);
t_player				*get_player(t_player *players, int num);
void					check_cards(t_general *all, t_card *cards);
void					check_args_and_exe_op(t_general *all, t_card *card);
int						count_skiplen(t_card *card, int desire_arg);
int						get_arg_value(unsigned char *arena, t_card *card,
						int num, bool mod);
int						get_nreg(unsigned char *arena, t_card *card);
int						cursor_to(int go_to);
int						cursor_move(t_card *card);
int						cursor_steps(int current_position, int count);
void					get_op_links(t_general *all);
void					add(t_general *all, t_card *card);
void					aff(t_general *all, t_card *card);
void					and(t_general *all, t_card *card);
void					fork_m(t_general *all, t_card *card);
void					load(t_general *all, t_card *card);
void					ldi(t_general *all, t_card *card);
void					lfork(t_general *all, t_card *card);
void					live(t_general *all, t_card *card);
void					lld(t_general *all, t_card *card);
void					lldi(t_general *all, t_card *card);
void					or(t_general *all, t_card *card);
void					st(t_general *all, t_card *card);
void					sti(t_general *all, t_card *card);
void					sub(t_general *all, t_card *card);
void					xor(t_general *all, t_card *card);
void					zjmp(t_general *all, t_card *card);

#endif
