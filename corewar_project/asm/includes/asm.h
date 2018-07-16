/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:53:35 by srossi            #+#    #+#             */
/*   Updated: 2018/07/13 15:41:52 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "op.h"

typedef struct	s_token
{
	int				type;
	char			*s_val;
	int				i_val;
	char			opcode;
	unsigned char	ocp;
	int				pos;
	int				last_op_pos;
	int				line;
	int				cl;
	char			arg_size;
	char			nb_params;
	struct	s_token	*next;
}				t_token;

typedef struct s_asm
{
	char			tab[CHAMP_MAX_SIZE];
	struct 	s_token *atoken;
	char			comment[COMMENT_LENGTH + 1];
	char			name[PROG_NAME_LENGTH + 1];
	char			*code;
	char			*err_log;
	char			err_content[COMMENT_LENGTH];
	int				addon;
//	int				nb_instr;
	int				comma_f;
	int				comment_f;
	int				comchr_f;
	int				directchr_f;
	int				end;
	int				eof;
	int				error;
	int				err_pos;
	int				fp;
	int				fd_cor;
	int				gnl;
	int				label_f;
	int				line_nb;
	int				name_f;
	int				nb;
	int				nb_comma;
	int				nb_param;
	int				nb_params;
	int				nb_labelchr;
	int				last_opcode;
	int				last_op_pos;
	int				lock;
	int				operator_f;
	int				pos;
	int				quote;
	int				size;
	int				start;
	int				stop;
	char 			cur_param;
	char 			nb_params_left;
	struct s_label	*label;
}				t_asm;

typedef struct s_op
{  
	char	*name;
	int		nb_params;
	char	param_type[MAX_ARG];
	char 	opcode;
	int		nb_cycles;
	char	*description;
	char 	mod_carry;
	char	dir_oct_size; //0 = 4 octets et 1 = 2 octets
}				t_op;

extern t_op op_tab[NB_INSTR + 1];

/*
 * parsing
 */
//void	ft_parse_cmd(t_asm *info, char *line);
//void	ft_parse_op(t_asm *info, char *line);
void	retrieve_line(t_asm *info, char *line);
void	parse_correctly(t_asm *info, char *line);
char	*retrieve_word(t_asm *info, char *line);
void	ft_gnl(t_asm *info);
//void	ft_name(t_asm *info, char *line);
//void	ft_comment(t_asm *info, char *line);
void	analyse_separator(t_asm *info, char *line);
int		ft_is_labelchar(int *ptr, char c);
int		ft_is_space(char c);
int		ft_is_sep(char c);
int		ft_is_nonsep(char c);

int		ft_is_othchr(char c);
int		ft_is_comchar(int *num, char c);
//int		ft_split_word(t_asm *info, char *line, int i);
void	reset_words_flags(t_asm *info, char **arg);
//int 	ft_keep_going(t_asm *info, char *line, int i);

/*
 * Error
 */
void	ft_error(int a);
void	parsing_error(t_asm *info, char *line);
void	ft_syntax_err(t_asm *info, int i, char *line);
void	ft_error_management(t_asm *info, char *arg);
void	command_name_error(t_asm *info, char *arg);
/*
* Lexical analysis
*/

void	ft_line_split(char *line);
void	ft_display_token(t_token *token);
int		ft_is_reg(char *arg);
int		ft_is_label(char *arg);
int		ft_is_dir(char *arg);
int		ft_is_ind(char *arg);
int		ft_get_ival(char *arg);
int		ft_get_type(char *arg);
int		ft_get_opcode(char *arg);
int		ft_is_op(char *arg);

/*
* Syntax analysis
*/

int	ft_is_valid_syntax(t_asm *info);

/*
** Fonctions tokens
*/

void	ft_token_add(t_asm *sasm, char *arg);
void	ft_token_add_tail(t_token **token, t_token *new_token);
void	ft_token_init(t_token *new_token);
//void	ft_token_free(t_token *token);
void	ft_token_list_free(t_token *a_token);
void	ft_token_load(t_asm *sasm, t_token *token, char* arg);
//t_token	*ft_token_new();
void	ft_token_display(t_token *token, int token_nb);
void	ft_token_display_all(t_token *atoken);

/*
** FONCTIONS DE TESTS
*/

void	ft_test_params();
void	ft_test_label();
void	ft_tests_syntax();

/*
** FONCTION AFFICHAGE CHAMP
*/
void	ft_display(t_asm *sasm);

/*
** FONCTION CREER CHAMP
*/
void	ft_create_champ(t_asm *info);
/*
** FONCTIONS RECHERCHE/REMPLISSAGE LABELS
*/

void	ft_fill_labels(t_token *atoken);
char *ft_clean_label(char *label);
t_token		*ft_find_label(t_token *atoken, char *label);
//void	ft_fill_label(t_token *token_src, t_token *token_dst);
/*
** FONCTIONS ECRIRE SHORT OU INT DECOMPOSE EN OCTETS 
*/
void	ft_write_int(int nb, int fd_cor);
void	ft_write_int(int nb, int fd_cor);
void	ft_write_short(short nb, int fd_cor);
void	ft_write(t_asm *info);

/*
** FONCTIONS SWAP BITS INT OU SHORT 
*/

void	ft_swap_bytes_int(unsigned char *t);
void	ft_swap_bytes_short(unsigned char *t);

/*
void	ft_display_param(t_param *param, int param_id);
void	ft_display_instruction(t_instruction *instruction);
void	ft_display_label(t_label *label);
void	ft_display_asm(t_asm *sasm);
void	ft_label_add_tail(t_asm *sasm, t_label *new_label);
void	ft_label_new(t_asm *sasm, char *label_name);
void	ft_label_free(t_label *label);
void	ft_label_add_instruction(t_label *label, t_instruction *new_instruction);
void	ft_instruction_free(t_instruction *instruction);
void	ft_instruction_free_all(t_label *label);
void	ft_param_free(t_param *param);
void	ft_split_line(t_asm *sasm, char *line);
void	ft_load_asm_instruction(t_asm *sasm, char **tab);
void	ft_load_instruction_params(t_instruction *instruction, char **tab);
int		ft_is_valid_line(char **tab, char **tab_params);
int		ft_load_asm(t_asm *sasm, char **tab);
int		ft_strtab_nblines(char **tab);
*/
#endif
