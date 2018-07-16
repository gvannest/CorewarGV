/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:47:09 by msicot            #+#    #+#             */
/*   Updated: 2018/07/16 11:34:24 by msicot           ###   ########.fr       */
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
	char *lol;

	lol = line;
	//	ft_printf("test [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n", info->line_nb, info->start + 1, info->err_log);
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
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ENDLINE\n", info->line_nb + 1, 1);

	}
	else if (info->error == 5)
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] END \"%s\"\n", info->line_nb, info->end + 1, line);
	}
	//free
		//exitt
	
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
