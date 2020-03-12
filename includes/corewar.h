/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejskobelev <andrejskobelev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:11:30 by andrejskobe       #+#    #+#             */
/*   Updated: 2020/03/12 14:11:51 by andrejskobe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# define ZEROS 00000000
# include "../libft/headers/libft.h"
# include "op.h"
# include "operations.h"

typedef struct			s_op //  для op.c
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
	char				*name;
	unsigned char		*exe_code;
	int					code_size;
	int					len_exec;
	char				*comment;
	struct s_player		*next;
	struct s_player		*prev;
}						t_player;

typedef struct			s_card // каретка
{
	bool				carry;
	int					num;
	int					code_op;
	int					alive_cycle;
	int					cursor;
	int					cycles_to_op;
	int					regs[REG_NUMBER];
	t_op				*op; // операция которую будет исполнять каретка
	t_player			*player;
	struct s_card		*next;
	struct s_card		*prev;
}						t_card;

typedef struct			s_arena // для того чтобы было меньше if и память была зациклена 
{
	unsigned char		*map;
	int					ind;
}						t_arena;

typedef struct			s_general // хранит все что нужно для игры
{
	void				(*operations[16])(struct s_general *, t_card *, char *); // ссылки на операции
	t_player			*last_live; // о ком посл. раз сказали что он жив
	t_player			*players; // список игроков
	t_card				*cards; // список кареток
	t_op				*op_tab;
	t_arena				arena;
	int					n_live_op;
	int					flag_n;
	int					checks_count;
	int					n_players;
	int					stop_cycle;
	int					ctd; // cycle to die
	int					cycles; // кол-во прошедших циклов
	int					change_ctd;
}						t_general;

void					prepare_game(t_general *all);
void					check(t_general *all);
t_player				*init_player();
void					read_player(char **argv, t_general *all);
void					valid_check(int fd, char *argv, t_general *all);
void					check_magic(int fd);
void					check_name(int fd, t_player *player);
void					check_zeros(int fd);
void					length_exec_code(int fd, t_player *player);
void					champ_comment(int fd, t_player *player);
void				    check_champ_code(int fd, t_player *player);
t_player				*skip_box(t_player *player);
void					write_error();
char					get_char(t_arena *arena, int num);
int						get_bytes(t_arena *arena, int start, int size);
char					next(t_arena *arena);
void					set_byte(t_arena *arena, unsigned char byte, int num);
void					set_reg(t_arena *arena, int reg, int adress);
int						set_mem(t_arena *arena, unsigned char *mem, int num, int size);
void					get_op_tab(t_general *all);
t_player				*get_player(t_player *players, int num);
int						count_skiplen(char *args, int desire_arg, int t_dir_size);
int						get_arg_value(t_general *all, char *args, int num, bool mod);
int						get_nreg(t_arena *arena, char *args, int num, int t_dir_size);
int						cursor_to(int go_to);
int						cursor_next(int current_position);
int						cursor_steps(int current_position, int count);
void					live(t_general *all, t_card *card, char *args);
void					load(t_general *all, t_card *card, char *args);
void					st(t_general *all, t_card *card, char *args);
void					add(t_general *all, t_card *card, char *args);
void					sub(t_general *all, t_card *card, char *args);
void					and(t_general *all, t_card *card, char *args);
void					or(t_general *all, t_card *card, char *args);
void					xor(t_general *all, t_card *card, char *args);
void					zjmp(t_general *all, t_card *card, char *args);
void					ldi(t_general *all, t_card *card, char *args);
void					sti(t_general *all, t_card *card, char *args);
void					fork_m(t_general *all, t_card *card, char *args);
void					lld(t_general *all, t_card *card, char *args);
void					lldi(t_general *all, t_card *card, char *args);
void					lfork(t_general *all, t_card *card, char *args);
void					aff(t_general *all, t_card *card, char *args);
void					get_op_links(t_general *all);

#endif
