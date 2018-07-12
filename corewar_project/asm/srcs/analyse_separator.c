/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_separator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:26:54 by msicot            #+#    #+#             */
/*   Updated: 2018/07/11 14:48:25 by msicot           ###   ########.fr       */
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

static void comma_analyser(t_asm *info)
{
	/* 1- Est ce que flag comma_f est on ?
	 * Si oui cest qu'il y a deja une virgule avant -> erreur
	 * Si non, allumer le flag et augmenter le nombre de virgule.
	 * il faudra dans la fonction qui recupere l'argument penser a reset le flag virgule apres chaque retrieve dargument.
	 */
	if (info->comma_f == 1 || info->nb_param == 0)
	{
		info->error = 1;
	}
	else 
	{
		info->comma_f = 1; 
		++info->nb_comma;
	}
}

static void quote_analyser(t_asm *info)
{
	if (info->comment_f != -1 && info->name_f != -1)
		info->error = 1;
	else
	{
		if (info->comment_f == -1 && info->name_f != -1)
		{
			++info->quote;

		}
		else if (info->comment_f != -1 && info->name_f == -1)
		{
			++info->quote;
		}
		else
		{
			info->error = 1;
			return ;
		}
		if (info->quote == 2)
		{
			info->lock = 1;
			info->quote = 0;
		}
	}
}

static void	space_analyser(t_asm *info)
{
	if (info->nb_param != 0)
		info->error = 1;
}

void analyse_separator(t_asm *info, char *line)
{
	ft_printf("analyse_separator. quote = %d\n", info->quote);
	if (line == NULL)
	   return ;	
	if (START == SEPARATOR_CHAR)
	{
		comma_analyser(&(*info));
	}
	else if (START == '"')
	{
		quote_analyser(&(*info));
	}
	else if (ft_is_space(START))
	{
		space_analyser(&(*info));
	}
	
	ft_printf("start=%d, end=%d  len=%ld\n", info->start, info->end, ft_strlen(line));
	info->end = info->start + 1;
	ft_printf("start=%d, end=%d  len=%ld\n", info->start, info->end, ft_strlen(line));
	/*	else if (START == COMMENT_CHAR)
	{
		info->comchr_f = 1;
	}*/
/*	else if (START == SEPARATOR_CHAR)
	else if (START == COMMENT_CHAR)
		++info->quote;
	else if (START == LABEL_CHAR)*/
}

