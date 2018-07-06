
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
	if (info->operator_f == 0)
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
		if (line[i] == LABEL_CHAR)
		{
			if(labelchar(&(*info)))
				break ;

		}
		else if (line[i] == SEPARATOR_CHAR)
		{
			if (sepachar(&(*info)))
				break ;
		}
		else if (line[i] == DIRECT_CHAR)
		{
			dirchar(&(*info));
			
		}
		if (ft_is_comchar(&info->comchr_f, line[i]))
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
	i = ft_keep_going(&(*info), line, i);
	if (i != info->start)
	{
		info->end = i;
		arg = ft_strsub(line, info->start, info->end - info->start);
		if (info->operator_f == -1)
			info->operator_f = 1;
		//ft_token_add(&(*info), &(*arg));
		if (info->error != 0)
		{
			info->code = arg;
		//	ft_printf("Error on TOKEN");
		//ft_printf("->%s<-\n", arg);
		}
		//		ft_printf("start=%d, end=%d \n", info->start, info->end);
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
	//ft_printf("ft_parse_op\n");
	while (line[i] && info->error == 0)
	{
		info->addon = 0;
		 if (!ft_is_space(line[i]))
		 {
			i = ft_split_word(&(*info), line, i);
		 }
		 if (info->comchr_f == 1 || i >= (int)ft_strlen(line))
			 break ;
		 i++;
	}
}
