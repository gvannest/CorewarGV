/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_correctly.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:59:05 by msicot            #+#    #+#             */
/*   Updated: 2018/07/17 14:17:10 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
 * Comment parser correctement ? 
 * il faut trouver des mots, separes par des separateurs. 
 * un mot est une chaine de char entoures de separateurs
 * une commande est un mot suivi par des balises guillemets '"'
 * Lorsque je parcours ma chaine de char il y plusieurs phases : 
 * 	1-Avancer tant que l'on est sur des espaces si quote = 0;
 * 	2- On tombe sur une lettre quand quote = 0
 * 	3- on calcule la longueur du mot grace a une fonction length word.
 * 	4- on memorise ce nom dans un argument
 * 	5- on l'envoie dans uyne fonction qui va le parser pour verifier son contenu
 * 	et sa validite
 *
 *
 *
 */

/* info->lock == 1, err = 1;
 * Si on a un mot alors que la line est lock
 * cela signifie que le mot est une erreur et qu'une autre 
 * instruction etait attendu
 *
 */

void	check_error(t_asm *info, char *arg)
{
	if (info->comment_f == -1 || info->name_f == -1)
	{
		info->error = 1;
	//	ft_printf("check error\n");
		parsing_error(info, arg);
	}
}

static void	ft_check_before_sending(t_asm *info, char *arg)
{
	int	send;

	send = 1;
	if (send == 1)
	
	//	ft_printf("check error\n");
	//	ft_printf("PRE TOKEN ADD\n");
	if (send == 1 && arg != NULL)
		ft_token_add(info, arg);		//send to savinien !!!!!!!!
	//	ft_printf("POST TOKEN ADD\n");
}

static void	check_word(t_asm *info, char *arg)
{
	static int index = 0;
	if (info->lock == 1)
	{
		info->error = 2;
		parsing_error(info, arg);
	}
	else if (info->comment_f == 0 || info->name_f == 0)
	{
		if (ft_strequ(arg, ".comment"))
			info->comment_f = -1;
		else if (ft_strequ(arg, ".name"))
			info->name_f = -1;
		else
			command_name_error(info, arg);
	//	ft_printf("check word, locking\n");
		info->lock = 1;
	}
	else
	{
//		ft_error_management(info, arg);
		ft_check_before_sending(info, arg);
	}
	index++;
}

char	*retrieve_word(t_asm *info, char *line)
{
	char	*arg;
	int		i;

	i = info->start;
	while (line[i] && (ft_strchr(LABEL_CHARS, line[i]) || ft_is_nonsep(line[i])))
	{
		++i;
	}
	info->end = i;
	if (i >= info->start)
	{
		arg = ft_strsub(line, info->start, i - info->start);
	//	ft_printf("arg ->%s<- i=%d\n", arg, i);
		info->err_log = ft_strdup(arg);
	}
	else
		return (ft_strnew(0));
	return (arg);
}


static int	ft_parse_it(t_asm *info, char *line)
{
	char	*arg;
	//ft_printf("\tparsing it start=%d ->%c<-_\n", info->start, line[info->start]);
	if (info->quote == 1)
		retrieve_line(&(*info), line);
	else if (ft_is_sep(line[info->start]) || line[info->start] == '"')
	{
		analyse_separator(info, line);
	}
	else if (!ft_is_comchar(&info->comchr_f, line[info->start]))
	{
		arg = retrieve_word(&(*info), line);
		check_word(info, arg);
//		check_error(info, arg);
		ft_strdel(&arg);
		ft_strdel(&info->err_log);
	}
	return (info->end);
}

void	parse_correctly(t_asm *info, char *line)
{
	int	i;

	i = 0;
	if (line != NULL && info->quote == 1 && line[0] == '\0')
		retrieve_line(&(*info), line);
	while (line[i] != '\0' && info->error == 0 && info->stop == 0)
	{
		if (ft_is_space(line[i]) && info->quote != 1)
			++i;
		else
		{
			info->start = i;
			i = ft_parse_it(&(*info), line);
		}
		if (info->comchr_f == 1)
		{
			break ;
		}
	}
	ft_error_management(info, line);
}
