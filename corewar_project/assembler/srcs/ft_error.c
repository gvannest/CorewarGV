/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:47:09 by msicot            #+#    #+#             */
/*   Updated: 2018/07/19 16:52:46 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_instr(t_asm *info, char *arg)
{
	if (ft_strequ(arg, ".name"))
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] COMMAND_NAME \"%s\"\n", info->line_nb, info->start + 1, info->err_log);
	}
	else if (ft_strequ(arg, ".comment"))
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] COMMAND_COMMENT \"%s\"\n", info->line_nb, info->start + 1, info->err_log);
	}
	else
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n", info->line_nb, info->start + 1, info->err_log);
}

void	parsing_error(t_asm *info, char *line)
{
	if (info->error == 1)
	{
		ft_printf("Error=1 Syntax error at token [TOKEN][%03d:%03d] \"%s\"\n", info->line_nb, info->start + 1, info->err_log);
	}
	else if (info->error == 2)
	{
		error_instr(info, line);
	}
	else if (info->error == 3)
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] SEPARATOR \"%s\"\n", info->line_nb, info->start + 1, line);
	}
	else if (info->error == 4)
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ENDLINE\n", info->line_nb, info->end + 1);
	}
	else if (info->error == 5)
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] END \"%s\"\n", info->line_nb, info->end + 1, line);
	}
	else if (info->error == 6)
	{
		ft_printf("Lexical error at [%d:%d]\n", info->line_nb, info->end + 1);
	}
	if (line != NULL)
		ft_strdel(&line);
	if (info->err_log != NULL)
		ft_strdel(&info->err_log);
	exit (0);

}

void	ft_error(int a)
{
	if (a == 1)
	{
		perror("Error");
		//		exit(0);
	}
	else
		return ;
}

static	char *ft_type_char(int type)
{
	if (type == T_DIR || type == T_DIR_LAB)
		return "direct";
	else if (type == T_IND || type == T_IND_LAB)
		return "index";
	else if (type == T_REG)
		return "register";
	else if (type == T_LAB)
		return "label";
	else
		return "unknown";
}

void	ft_error_param(t_asm *info, t_token *token, int nb_error)
{
	if (nb_error == 1)
		printf("Invalid parameter count for instruction %s\n", op_tab[info->last_opcode - 1].name);
	else if (nb_error == 2)
			printf("Invalid parameter %d type %s for instruction %s\n", info->cur_param, ft_type_char(token->type), op_tab[info->last_opcode - 1].name);
	else if (nb_error == 3)
			printf("Invalid parameter %d type %s for instruction %s\n", info->cur_param - 1, ft_type_char(token->type), op_tab[info->last_opcode - 1].name);
	else if (nb_error == 4)
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n", info->line_nb, info->start + 1, token->s_val);
	else if (nb_error == 5)
		ft_printf("Champion size is too big.\n");
	else if (nb_error == 6)
		ft_printf("Lexical error at [%d:%d]\n", info->line_nb, info->end);
	exit (EXIT_FAILURE);
}
