/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_correctly.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:59:05 by msicot            #+#    #+#             */
/*   Updated: 2018/07/11 14:48:27 by msicot           ###   ########.fr       */
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

void	check_word(t_asm *info, char *arg)
{
	if (info->comment_f == 0 || info->name_f == 0)
	{
		if (ft_strequ(arg, ".comment"))
			info->comment_f = -1;
		else if (ft_strequ(arg, ".name"))
			info->name_f = -1;
	}
	else
	{
		//send to savinien !!!!!!!!
	}
}

char	*retrieve_word(t_asm *info, char *line)
{
	char	*arg;
	int		i;

	i = info->start;

	while (line[i] && (ft_strchr(LABEL_CHARS, line[i]) || line[i] == '.'))
	{
		ft_printf("ret_word ->%c<-\n", line[i]);
		++i;
	}
	if (i > info->start)
	{
		arg = ft_strsub(line, info->start, i - info->start);
		ft_printf("->%s<- i=%d\n", arg, i);
	}
	else
		return (NULL);
	info->end = i;
	return (arg);
}


int	ft_parse_it(t_asm *info, char *line)
{
	char	*arg;

	if (info->quote)
		info->quote = 1;//		retrieve_line(&(*info), line);
	else if (ft_is_othchr(line[info->start]))
	{
		analyse_separator(&(*info), line);
	}
	else 
	{
		arg = retrieve_word(&(*info), line);
		if (arg != NULL)
		{
			check_word(&(*info), arg);
		}
		ft_strdel(&arg);
	}
	return (info->end);
}

void	parse_correctly(t_asm *info, char *line)
{
	int	i;

	i = 0;
	while (line[i] && info->error == 0)
	{
		if (ft_is_space(line[i]) && info->quote != 1)
			++i;
		else
		{
			info->start = i;
			i = ft_parse_it(&(*info), line);
		}
	}
}
