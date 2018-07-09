/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:54:13 by msicot            #+#    #+#             */
/*   Updated: 2018/07/09 16:55:21 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	set_var(t_asm *info)
{
	info->end = 0;
	info->comchr_f = 0;
	info->start = 0;
	info->comma_f = 0;
	info->operator_f = 0;
	info->label_f = 0;
	info->comchr_f = 0;
	info->directchr_f = 0;
	info->nb_comma = 0;
	info->nb_param = 0;

}

void	reset_words_flags(t_asm *info, char **arg)
{
	if (info->operator_f == 0 && info->comment_f == 1 && info->name_f == 1)
		info->operator_f = -1;
	info->directchr_f = 0;
	info->nb_labelchr = 0;
	info->directchr_f = 0;
	arg = NULL;
	if (info->operator_f == 1)
		++info->nb_param;
	info->error = (info->nb_param > 3) ? 1 : info->error;
}

/*
#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','
#define	COMMAND_CHAR			'.'
#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"
*/

static int	labelchar(t_asm *info)
{
	if (info->operator_f == -1 && info->label_f == 0)
	{
			++info->label_f;
			info->operator_f = 0;
	//		ft_printf("break ?\n");
			return (1);
	}
	else if (info->operator_f == 1 && info->directchr_f > 0)
	{
		++info->nb_labelchr;
		return (0);
	}
	else
	{
		info->error = 1;
		return (0);
	}
}

static int	sepachar(t_asm *info)
{
	++info->nb_comma;
	if (info->nb_comma > info->nb_param || info->nb_comma > 2 || info->comma_f == 1)
	{
		info->error = 1;
		return (1);
	}
//	info->comma = 1;
	return (1);
}

static int	dirchar(t_asm *info)
{
	if (info->directchr_f == 0)
	{
		//ok
		info->directchr_f = 1;
		return (1);
	}
	info->error = 1;
	return (1);	

}

static	int ft_keep_going(t_asm *info, char *line, int i)
{
	info->start = i;
	while (line[i] && (ft_strchr(LABEL_CHARS, line[i]) || 
				ft_is_othchr(line[i])))// && !ft_is_sep(line[i]))
	{
		if (line[i] == '"')
		{
		//	ft_printf("quote found alors que non\n");
			++info->quote;
			break ; 
		}
		else if (line[i] == LABEL_CHAR && info->quote == 0)
		{
			if(labelchar(&(*info)))
			{
				++i;
				break ;
			}
		}
		else if (line[i] == SEPARATOR_CHAR && info->quote == 0)
		{
			if (sepachar(&(*info)))
				break ;
		}
		else if (line[i] == DIRECT_CHAR && info->quote == 0)
		{
			dirchar(&(*info));
		}
		else if (ft_is_comchar(&info->comchr_f, line[i]) && info->quote != 1)
			break ;
		++i;
	}	
	return (i);
}

//void	reset_words_flags(t_asm *info)
static	int	ft_split_word(t_asm *info, char *line, int i)
{
	char	*arg;

	reset_words_flags(&(*info), &arg);
//	ft_printf("\ti = %d, info->end = %d\n", i, info->end);
	i = ft_keep_going(&(*info), line, i);
	if (i != info->start)
	{
		info->end = i;
		arg = ft_strsub(line, info->start, info->end - info->start);
		ft_printf("->%s<- \n",arg );
		if (info->operator_f == -1)
			info->operator_f = 1;
		if (info->error != 0)
		{
			info->code = arg;
		}
		if (ft_strequ(arg, ".name") && info->name_f == 0)
		{
			info->name_f = -1;
		}
		else if (ft_strequ(arg, ".comment") && info->comment_f == 0)
		{
			info->comment_f = -1;
		}
		ft_strdel(&arg);
		info->comma_f = (info->comma_f = 1 && info->error == 0) ? 0 : info->comma_f;
		return (info->end);
	}
	return (i);
}

void	ft_parse_op(t_asm *info, char *line)
{
	int i;

	i = 0;
	if (!line)
		return ;
	set_var(&(*info));
	if (ft_strlen(line) == 0 && info->quote == 1)
		retrieve_line(&(*info), line, i);
//	ft_printf("Treating line->%s<- quote =%d\n", line, info->quote);
	while (line[i] && info->error == 0)
	{
		if (!ft_is_space(line[i]) || info->quote == 1)
		{
			if (info->quote == 1)
				i = retrieve_line(&(*info), line, i);
			else
			{
				i = ft_split_word(&(*info), line, i);
			}
		}
		if (line[i] == '"')
			++info->quote;
		if (info->comchr_f == 1 || i >= (int)ft_strlen(line))
			break ;
		i++;
	}
}
