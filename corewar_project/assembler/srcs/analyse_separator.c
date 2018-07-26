/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_separator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:26:54 by msicot            #+#    #+#             */
/*   Updated: 2018/07/17 15:56:31 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#define START line[info->start]

/*
 * #define COMMENT_CHAR			'#'
 * #define LABEL_CHAR				':'
 * #define DIRECT_CHAR				'%'
 * #define SEPARATOR_CHAR			','
 * #define	COMMAND_CHAR			'.'
 * #define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
 * #define NAME_CMD_STRING			".name"
 * #define COMMENT_CMD_STRING		".comment"
 * */

static void comma_analyser(t_asm *info, char *line)
{
	/* 1- Est ce que flag comma_f est on ?
	 * Si oui cest qu'il y a deja une virgule avant -> erreur
	 * Si non, allumer le flag et augmenter le nombre de virgule.
	 * il faudra dans la fonction qui recupere l'argument penser a reset le flag virgule apres chaque retrieve dargument.
	 */
	if (info->comma_f == 1 || (info->nb_comma > info->nb_param) || info->operator_f == 0 || info->nb_param == 0)
	{
//		ft_printf("ERROR comma analyser\n");
		info->error = 3;
		parsing_error(info, ft_strdup(","));
	}
	else if (info->end + 1 == (int)ft_strlen(line))
	{
		info->error = 4;
		parsing_error(info, ft_strdup(","));
	}
	else
	{
		info->comma_f = 1; 
		++info->nb_comma;
	}
//	ft_printf("comma_f=%d\tnb_comma=%d\t\n", info->comma_f, info->nb_comma);	
}

static void quote_analyser(t_asm *info)
{
	if (info->quote == 0 && info->comment_f != -1 && info->name_f != -1)
	{
	//	ft_printf("ERROR quote analyser\n");
		info->error = 1;
	}
	else
	{
		if (info->quote == 0)
		{
			++info->quote;
			info->lock = 0;
		}
		else if (info->quote == 2)
		{
			info->lock = 1;
			info->quote = 0;
		}
	}
}

void analyse_separator(t_asm *info, char *line)
{	
	if (line == NULL)
	   return ;	
	if (START == SEPARATOR_CHAR)
	{
		comma_analyser(info, line);
//		if (info->comma_f == 1)
//			ft_printf("flag allume\n");
	}
	else if (START == '"')
	{
		quote_analyser(info);
	}
	info->end = info->start + 1;
}
