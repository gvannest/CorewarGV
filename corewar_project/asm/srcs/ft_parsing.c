/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:54:26 by msicot            #+#    #+#             */
/*   Updated: 2018/07/12 12:15:01 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	reset_flags(t_asm *info)
{
	info->lock = 0;
	info->start = 0;
	info->end = 0;
	info->comchr_f = 0;
	info->comma_f = 0;
	info->operator_f = 0;
	info->label_f = 0;
	info->comchr_f = 0;
	info->directchr_f = 0;
	info->nb_comma = 0;
	info->nb_param = 0;
	info->addon = info->line_nb;
}

static void	ft_check_data(t_asm *info)
{
	//check comment name
	//	ft_printf("check comment & name\n");
	if (((info->error != 1) || (info->error == 0 && info->quote == 0)) && (info->name_f != 1 || info->comment_f != 1))
	{
		info->error = 1;
		parsing_error(info, "\0");
	}
}

static void	check_line(t_asm *info, char *line, int len)
{
	int i;
	
	i = len;
	if (line == NULL)
		return ;
	reset_flags(&(*info));
	parse_correctly(&(*info), line);

	/*	if ((info->name_f == -1 || info->comment_f == -1) && info->quote == 0)
	{
		info->error = 0;
	}
	else
		ft_parse_op(&(*info), line);
		*/

}

void		ft_gnl(t_asm *info)
{
	char	*line;

	line = 0;
	while ((info->gnl = get_next_line(info->fp, &line)) > 0 && info->error == 0
			&& info->stop == 0)
	{
	//	ft_printf("****************************\n");
	//	ft_printf("GNL->%s\n", line);
		++info->line_nb;
		check_line(&(*info), line, ft_strlen(line));
		if (info->error == 1)
			parsing_error(info, line);
		ft_strdel(&line);
	//	ft_printf("**************************** error=%d\n\n", info->error);
	}
	ft_check_data(&(*info));
	free(line);
//	ft_printf("Name %d =%s\nComment %d =%s  error=%d", info->name_f, info->name, info->comment_f, info->comment, info->error);
}


/*	if (info->comment_f <= 0 || info->name_f <= 0)
	{
//		printf("parse cmd\n");
		ft_parse_cmd(&(*info), line);
	}
	else if (info->comment_f == 1 && info->name_f == 1)
//	{
//		printf("parse op\n");*/

