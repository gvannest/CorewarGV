/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:54:26 by msicot            #+#    #+#             */
/*   Updated: 2018/06/28 13:23:19 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_check_data(t_asm *info)
{
	//check comment name
	ft_printf("check comment & name\n");
	if (info->name_f != 1 || info->comment_f != 1)
	{
	ft_printf("error check comment & name\n");
		info->error = 1;
		info->err_pos = 1;
	}
}

static void	check_line(t_asm *info, char *line, int len)
{
	int i;
	
	i = len;
//	printf("Chekc line ->%s<-\n", line);
	if (line == NULL)
		return ;
	if (info->comment_f <= 0 || info->name_f <= 0)
	{
//		printf("parse cmd\n");
		ft_parse_cmd(&(*info), line);
	}
	else if (info->comment_f == 1 && info->name_f == 1)
	{
	//	printf("parse op\n");
		ft_parse_op(&(*info), line);
	}
}

void		ft_gnl(t_asm *info)
{
	char	*line;

	line = 0;
//	printf("ft_gnl fp=%d\n", info->fp);
	while ((info->gnl = get_next_line(info->fp, &line)) > 0 && info->error == 0
			&& info->stop == 0)
	{
			++info->line_nb;
			check_line(&(*info), line, ft_strlen(line));
			if (info->error != -1)
				parsing_error(info, line);
			ft_strdel(&line);
	}
	ft_check_data(&(*info));
	free(line);
//	ft_printf("Name %d =%s\nComment %d =%s", info->name_f, info->name, info->comment_f, info->comment);
}
