/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 13:07:37 by msicot            #+#    #+#             */
/*   Updated: 2018/07/09 11:27:11 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_check_end(t_asm *info, char *line, int i)
{
	int len;

	len = ft_strlen(line);
	if (line[i] == '\0')
		return ; 
	else if (i == len)
		return ;
	else 
	{
		while (ft_is_space(line[i]))
				++i;
		if (line[i] == '#')
			return;
		else
		{
			printf("Error found\n");
			ft_syntax_err(&(*info), i, &line[i]);
		}
	}
}

/*
 **Comment
*/

static void	ft_comment2(t_asm *info, char *line, int i)
{
	int	nb;

	if (info->quote == 1 && line[i] != '"')
	{
		nb = ft_strlen(info->comment);
		if (nb + 1 < COMMENT_LENGTH)
			info->comment[nb] = line[i];
		else
			info->stop = 1;
	}
}

void	ft_comment(t_asm *info, char *line)
{
	int i;

	i = 0;
	if (!line)
		return ;
	while (line[i] && info->stop == 0 && info->quote != 2)
	{
		ft_comment2(&(*info), line, i);
		if (info->stop == 1)
			break ;
		if (line[i] == '"')
		{
			++info->quote;
			info->comment_f = (info->quote == 2) ? 1 : -1;
		}
		++i;
	}
//	printf("line[i] =->%c<-\n", line[i]);
	if (info->quote == 2 && line[i] != '\0')
	{
	//	ft_syntax_err(&(*info), i, &line[i]);y
		ft_check_end(&(*info), line, i);
	}
}

/*
 **Name
*/

static void	ft_name2(t_asm *info, char *line, int i)
{
	int	nb;

	if (info->quote == 1)
	{
		nb = ft_strlen(info->name);
		if (nb + 1 < PROG_NAME_LENGTH)
			info->name[nb] = line[i];
		else
			info->stop = 1;
	}
	else
		if (info->quote == 0)
		{
			info->stop = 1;
		}
}

void	ft_name(t_asm *info, char *line)
{
	int i;

//	printf("Flag name\n");
	i = 0;
	if (!line || line[0] == '\0')
		return ;
	while (line[i] && info->stop == 0 && info->quote != 2)
	{
		if (line[i] != '"')
			ft_name2(&(*info), line, i);
		if (line[i] == '"')
		{
			++info->quote;
			info->name_f = (info->quote == 2) ? 1 : -1;
		}
		++i;
	}
	if (info->quote == 2 && line[i] != '\0')
		ft_check_end(&(*info), line, i);
}
