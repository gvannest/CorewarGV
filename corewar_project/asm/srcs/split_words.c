/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 09:32:00 by msicot            #+#    #+#             */
/*   Updated: 2018/07/11 12:48:59 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_split_param(t_asm *info, char *arg)
{
//	ft_printf("Check split param ->%s<-\n", arg);
	if (info->lock == 1 && info->comchr_f == 0) //Line est verouillee, tout ce qui suit est une erreur
	{
//		ft_printf(" Is_locked\n");
		info->code = arg;
		info->error = 1;
		return ;
	}
	if (info->operator_f == -1)
		info->operator_f = 1;
	if (info->error != 0)
		info->code = arg;
	else if (ft_strequ(arg, ".name") && info->name_f == 0)
	{
		info->name_f = -1;
	//	ft_printf("name found\n");
	}
	else if (ft_strequ(arg, ".comment") && info->comment_f == 0)
	{
		info->comment_f = -1;
	//	ft_printf("comment found\n");
	}
	else if (info->comment_f == -1 || info->name_f == -1)
	{
		info->error = 1;
	}
}

int	ft_split_word(t_asm *info, char *line, int i)
{
	char	*arg;

	reset_words_flags(&(*info), &arg);
	i = ft_keep_going(&(*info), line, i);
	if (i > info->start && info->comchr_f == 0)
	{
		info->end = i;
		arg = ft_strsub(line, info->start, info->end - info->start);
	//	ft_printf("->%s<- start=%d, end=%d\n ", arg, info->start, info->end);
		check_split_param(&(*info), arg);
		if (info->error == 1)
			info->code = ft_strdup(arg);
		ft_strdel(&arg);
		info->comma_f = (info->comma_f = 1 && info->error == 0) ? 0 : info->comma_f;
		return (info->end);
	}
	return (i);
}
