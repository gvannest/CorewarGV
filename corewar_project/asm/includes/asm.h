/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:53:35 by srossi            #+#    #+#             */
/*   Updated: 2018/06/18 18:31:27 by srossi           ###   ########.fr       */
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
	struct 	s_label *label;
}			  t_asm;


void	ft_error(int a);
void	ft_gnl(int fp);
void	ft_display_param(t_param param, int param_id);
void	ft_display_instruction(t_instruction instruction);
void	ft_display_label(t_label label);
void	ft_display_asm(t_asm asm);

#endif
