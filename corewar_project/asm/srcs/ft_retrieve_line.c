/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retrieve_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:11:18 by msicot            #+#    #+#             */
/*   Updated: 2018/07/09 16:52:32 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	parse_line(t_asm *info, char *line, char *target, int i)
{
	int	len;

		
	len = ft_strlen(target);
	while (line[i] && info->stop == 0)
	{
		if (line[i] == '"')
		{
			++info->quote;
			++i;
			if (info->quote == 2 && info->comment_f == -1)
				info->comment_f = 1;
			else if (info->quote == 2 && info->name_f == -1)
				info->name_f = 1;
			if (info->quote == 2)
				info->quote = 0;
			else
				info->error = 1;
			break;
		}
		else
		{
		//	ft_printf("parse_line ...\n");
			if (len + 1 < ((info->comment_f == -1) ? COMMENT_LENGTH : PROG_NAME_LENGTH))
			{
				if (line[i])
				target[ft_strlen(target)] = line[i];
			}
			else
			{
				info->stop = 1; // a etoffer
				break ; 
			}
		}
		++i;
	}
	return (i);
}
//COMMENT_LENGTH (2048)
//PROG_NAME_LENGTH	128

int		retrieve_line(t_asm *info, char *line, int i)
{
//	ft_printf("retrieve_line\n");
	if (info->comment_f == -1)
	{
		i = parse_line(&(*info), line, &(*info->comment), i);
		if (info->comment_f == -1)
			info->comment[ft_strlen(info->comment)] = '\n';
	}
	else if (info->name_f == -1)
	{
		i = parse_line(&(*info), line, &(*info->name), i);
		if (info->name_f == -1)
			info->name[ft_strlen(info->name)] = '\n';
	}
	return (i);
}
