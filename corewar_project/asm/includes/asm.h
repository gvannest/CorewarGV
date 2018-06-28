/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:53:35 by srossi            #+#    #+#             */
/*   Updated: 2018/06/27 16:09:47 by msicot           ###   ########.fr       */
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
//#include "../../includes/op.h"
# include "op.h"

typedef struct	s_param
{
	char	type;
	char	*type_name;
	int		int_value;
	char	*str_value;
	char	f_label;
}				t_param;

typedef struct	s_instruction
{
	char	*name;
	char	ocp;
	char	opcode;
	struct	s_param	param1;
	struct	s_param	param2;
	struct	s_param	param3;
	struct	s_instruction *next_instruction;
}				t_instruction;

typedef struct s_label
{
	char 	*name;
	struct	s_instruction *instruction;
	int		address;
	struct	s_label	*next_label; 

}			t_label;

typedef struct s_asm
{
	char 	*tab;
	char	comment[COMMENT_LENGTH];
	char	name[PROG_NAME_LENGTH];
	char	*code;
	char	err_content[COMMENT_LENGTH];
	int	quote;
	int	start;
	int	end;
	int nb;
	int	name_f;
	int	comment_f;
	int	fp;
	int	line_nb;
	int	error;
	int	err_pos;
	int	stop;
	int	gnl;
	int	eof;
	struct s_nb		*nb_s;
	struct s_label	*label;
}				t_asm;

typedef struct s_op
{  
	char	*name;
	int		nb_params;
	char	param_type[MAX_ARG];
	int 	opcode;
	int		nb_cycles;
	char	*description;
	int 	mod_carry;
	int		dir_oct_size; //0 = 4 octets et 1 = 2 octets
}				t_op;

/*
 * parsing
 */
void	ft_parse_name(t_asm *info, char *line);
void	ft_parse_cmd(t_asm *info, char *line);
void	ft_gnl(t_asm *info);
/*
 * Error
 */
void	ft_error(int a);
void	parsing_error(t_asm *info, char *line);
void	ft_syntax_err(t_asm *info, int i, char *line);

void	ft_display_param(t_param *param, int param_id);
void	ft_display_instruction(t_instruction *instruction);
void	ft_display_label(t_label *label);
void	ft_display_asm(t_asm *sasm);
void	ft_label_add_tail(t_asm *sasm, t_label *new_label);
void	ft_label_new(t_asm *sasm, char *label_name);
void	ft_label_free(t_label *label);
void	ft_label_add_instruction(t_label *label, t_instruction *new_instruction);
void	ft_instruction_new(t_label *label, char *label_name);
void	ft_instruction_free(t_instruction *instruction);
void	ft_instruction_free_all(t_label *label);
void	ft_param_free(t_param *param);
void	ft_split_line(t_asm *sasm, char *line);
void	ft_load_asm_instruction(t_asm *sasm, char **tab);
void	ft_load_instruction_params(t_instruction *instruction, char **tab);
int		ft_is_valid_line(char **tab, char **tab_params);
int		ft_load_asm(t_asm *sasm, char **tab);
int		ft_strtab_nblines(char **tab);

#endif
