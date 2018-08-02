/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:53:35 by srossi            #+#    #+#             */
/*   Updated: 2018/08/02 11:23:56 by srossi           ###   ########.fr       */
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
	int				cor_index;
	int				last_cor_index;
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
	int				cor_index;
	int				last_cor_index;
	int				last_opcode;
	int				last_op_pos;
	int				last_op_line;
	int				lock;
	char			f_option_h;
	char			f_option_d;
	int				operator_f;
	int				pos;
	int				quote;
	int				size;
	int				start;
	int				stop;
	char 			cur_param;
	char 			nb_params_left;
	char			*true_name;
	char			*path;
	int				nb_instr;
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

	extern t_op g_op_tab[NB_INSTR + 1];

/*
 * parsing
 */

void	ft_check_options(t_asm *info, int argc, char **argv);
int		ft_check_argv(t_asm *info, char **argv, int argc);
void	retrieve_line(t_asm *info, char *line);
void	parse_correctly(t_asm *info, char *line);
char	*retrieve_word(t_asm *info, char *line);
void	ft_gnl(t_asm *info);
void	analyse_separator(t_asm *info, char *line);
int		ft_is_labelchar(int *ptr, char c);
int		ft_is_space(char c);
int		ft_is_sep(char c);
int		ft_is_nonsep(char c, int f);
char	*ft_type_char(int type);
int		ft_is_othchr(char c);
int		ft_is_comchar(int *num, char c);
void	reset_words_flags(t_asm *info, char **arg);

/*
 * Error
 */
void	ft_error_syntax(t_asm *info);
void	parsing_error(t_asm *info, char *line);
void	ft_syntax_err(t_asm *info, int i, char *line);
void	ft_error_management(t_asm *info, char *arg);
void	command_name_error(t_asm *info, char *arg);
void	ft_error_param(t_asm *info, t_token *token, int nb_error);
void	ft_error_incomplete(t_asm *info, int nb_error);
/*
* Lexical analysis
*/

void	ft_line_split(char *line);
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



void	ft_free(t_asm *info);

/*
** Fonctions tokens
*/

void	ft_token_add(t_asm *sasm, char *arg);
void	ft_token_add_tail(t_token **token, t_token *new_token);
void	ft_token_init(t_token *new_token);
void	ft_token_list_free(t_token *a_token);
void	ft_token_load(t_asm *sasm, t_token *token, char* arg);

/*
** FONCTION CHAMP
*/

void	ft_display(t_asm *info);
int		ft_open_champ(char *path);
void	ft_option_display(t_asm *info);

/*
** FONCTION CREER/LOAD CHAMP
*/
void	ft_create_champ(t_asm *info);
void	ft_load_ocp(t_token *token_op);
void	ft_load_int(int nb, char *champ);
void	ft_load_short(short nb, char *champ);
/*
** FONCTIONS RECHERCHE/REMPLISSAGE LABELS
*/

void	ft_fill_labels(t_token *atoken);
char *ft_clean_label(char *label);
t_token		*ft_find_label(t_token *atoken, char *label);
/*
** FONCTIONS ECRIRE SHORT OU INT DECOMPOSE EN OCTETS 
*/

void	ft_write(t_asm *info);

/*
** FONCTIONS SWAP BITS INT OU SHORT 
*/

void	ft_swap_bytes_int(unsigned char *t);
void	ft_swap_bytes_short(unsigned char *t);

/*
** FONCTION FIND INDEX DANS OPTAB
*/

int	ft_find_index_arg(char *arg);

/*
** FONCTION CHECK TOKEN
*/

void	ft_check_token(t_asm *info, t_token *token);
/*
** FONCTIONS LOAD TOKEN
*/

void	ft_token_load(t_asm *info, t_token *token, char *arg);
void	ft_token_reload(t_asm *info, t_token *token);
void	ft_load_values_info(t_asm *info, char *arg, t_token *token);

/*
** FONCTION USAGE
*/

void	ft_print_usage(int argc, char **argv);

/*
** FONCTION HELP
*/

void	ft_help();

/*
** FONCTION INIT
*/

void	ft_init_info(t_asm *info);

#endif
