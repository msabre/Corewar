/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:22:03 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/23 23:22:53 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# define FD_SIZE 900
# include "../libft/headers/libft.h"
# include "op.h"

typedef struct			s_file
{
	char				*f_name;
	char				name[PROG_NAME_LENGTH];
	char				comment[COMMENT_LENGTH];
	int					a;
	char				zero[T_IND];
	int					fd;
	int					line_byte;
	int					text;
	int					n;
	int					c;
}						t_file;

typedef struct			s_exec
{
	int					inst;
	int					dir_size;
	char				*kta;
	unsigned char		ta;
	int					line_byte;
	int					n_bytes;
	char				*a1;
	int					ta1;
	char				*a2;
	int					ta2;
	char				*a3;
	int					ta3;
	struct s_exec		*next;
}						t_exec;

typedef struct			s_label
{
	char				*name;
	int					line_byte;
	struct s_label		*next;
}						t_label;

int						main(int argc, char **argv);
void					skolkovo(char *line, t_file *ssl);
t_file					*init_ssl(void);
t_exec					*init_exec(void);
void					check_name(char *line, t_file *ssl);
void					check_comment(char *line, t_file *ssl);
t_exec					*connecting_people(char *line, t_file *ssl);
void					compare(t_file *ssl, char *line, int j, t_exec *com);
void					compare_2(t_file *ssl, char *line, int j, t_exec *com);
void					live(t_file *ssl, char *line, t_exec *com);
void					ld(t_file *ssl, char *line, t_exec *com);
void					including_magic(int text);
void					write_error(char *str);
void					take_label(char *line, t_file *ssl,
						t_label **list, t_exec *co);
t_label					*cnl(char *name, int byte_c);
void					add_label(t_label **list, t_label *new);
void					take_arg1(char *line, t_file *ssl, t_exec *com);
void					take_arg2(char *line, t_file *ssl, t_exec *com);
int						is_limit(int c);
void					skip_probel(t_file *ssl, const char *line);
int						is_whitespace(int c);
void					no_comment(t_file *ssl, const char *li);
void					no_separator(t_file *ssl, char *line);
void					aff(t_file *ssl, char *line, t_exec *com);
void					lfork(t_file *ssl, char *line, t_exec *com);
void					ft_fork(t_file *ssl, char *line, t_exec *com);
void					zjmp(t_file *ssl, char *line, t_exec *com);
void					lld(t_file *ssl, char *line, t_exec *com);
void					st(t_file *ssl, char *line, t_exec *com);
void					add(t_file *ssl, char *line, t_exec *com);
void					take_arg3(char *line, t_file *ssl, t_exec *com);
void					sub(t_file *ssl, char *line, t_exec *com);
void					and(t_file *ssl, char *line, t_exec *com);
void					ft_or(t_file *ssl, char *line, t_exec *com);
void					ft_xor(t_file *ssl, char *line, t_exec *com);
void					ldi(t_file *ssl, char *line, t_exec *com);
void					lldi(t_file *ssl, char *line, t_exec *com);
void					sti(t_file *ssl, char *line, t_exec *com);
void					add_comand(t_exec *list, t_exec *new);
void					label_change(t_label *list, t_exec **com);
void					label_search1(t_label **list, t_exec **com);
void					label_search2(t_label **list, t_exec **com);
void					label_search3(t_label **list, t_exec **com);
void					arg_add(t_exec **com);
void					kod_type_arg(t_exec **com);
void					add_kta(t_exec **com, int i);
void					free_label(t_label *list);
void					free_exec(t_exec *com);
void					free_t_file(t_file *ssl);
void					line_to_write(t_exec **com, t_file *ssl);
void					line_to_write2(int k, t_file *ssl, int i,
						unsigned char *s);
void					including_size(t_file *ssl);
void					name_comment(char *line, t_file *ssl);
void					rename_f(int argc, char **argv, t_file **sl);
void					choose_n_c(char *line, t_file *ssl,
						char *n, char *c);
void					c_data(t_file *ssl, t_exec *com, t_label *list);
int						line_part(t_exec *com, unsigned char *s, int i, int n);
int						order_arg(t_exec *com, char **a, int ta, int n);
t_exec					*take_opera(t_file *ssl, char *line, int i,
						t_exec *com);
void					take_label2(char *line, t_file *ssl, int i,
						t_label **list);
void					check_comment2(char *line, t_file *ssl);
int						check_comment3(char *line, t_file *ssl, int j, char *s);
void					check_name2(char *line, t_file *ssl);
int						check_name3(char *line, t_file *ssl, int j, char *s);
void					take_arg1_r(char *line, t_file *ssl, t_exec *com,
						int i);
void					take_arg1_pr(char *line, t_file *ssl, t_exec *com,
						int i);
void					take_arg1_d(char *line, t_file *ssl, t_exec *com,
						int i);
void					take_arg1_n(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg1_neg(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg1_dv(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg1_pr_neg(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg2_r(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg2_pr(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg2_neg(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg2_d(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg2_n(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg2_dv(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg2_pr_neg(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg3_r(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg3_pr(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg3_pr_neg(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg3_neg(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg3_d(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg3_n(char *line, t_file *ssl,
						t_exec *com, int i);
void					take_arg3_dv(char *line, t_file *ssl,
						t_exec *com, int i);

#endif
