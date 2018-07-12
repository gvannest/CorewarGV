/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retrieve_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:11:18 by msicot            #+#    #+#             */
/*   Updated: 2018/07/12 12:01:08 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_line(t_asm *info, char *line, char *target)
{
	int	i;

	i = info->start;
	while (line[i] && line[i] != '"')
	{
		if (ft_strlen(target) + 1 < ((info->comment_f == -1) ? COMMENT_LENGTH : PROG_NAME_LENGTH))
		{
			if (line[i])
				target[ft_strlen(target)] = line[i];
		}
		else
		{
			info->error = 1; // a etoffer
			ft_printf("comment ou name trop long (retrieve line)\n");
			break ; 
		}
		++i;
	}
	if (line[i] == '"')
	{
		++info->quote;
		if (info->comment_f == -1)
			info->comment_f = 1;
		else if (info->name_f == -1)
			info->name_f = 1;
	}
	info->end = i;
//	ft_printf("parse whole line end=%d\n", info->end);
}

//COMMENT_LENGTH (2048)
//PROG_NAME_LENGTH	128

void	retrieve_line(t_asm *info, char *line)
{
//	ft_printf("\tRetrieve line start=%d\n", info->start);

	if (info->comment_f == -1)
	{
		parse_line(&(*info), line, &(*info->comment));
		if (info->comment_f == -1)
		{
		//	ft_printf("adding \\n\n");
			info->comment[ft_strlen(info->comment)] = '\n';
		}
	}
	else if (info->name_f == -1)
	{
		parse_line(&(*info), line, &(*info->name));
		if (info->name_f == -1)
		{
	//		ft_printf("adding \\n\n");
			info->name[ft_strlen(info->name)] = '\n';
		}
	}
}
