#include "asm.h"

static void	check_split_param(t_asm *info, char *arg)
{
	if (info->operator_f == -1)
		info->operator_f = 1;
	if (info->error != 0)
		info->code = arg;
	else if (ft_strequ(arg, ".name") && info->name_f == 0)
		info->name_f = -1;
	else if (ft_strequ(arg, ".comment") && info->comment_f == 0)
		info->comment_f = -1;
}

int	ft_split_word(t_asm *info, char *line, int i)
{
	char	*arg;

	reset_words_flags(&(*info), &arg);
	i = ft_keep_going(&(*info), line, i);
	if (i >= info->start && info->comchr_f == 0)
	{
		info->end = i;
		arg = ft_strsub(line, info->start, info->end - info->start);
		//ft_printf("->%s<-", arg);
		check_split_param(&(*info), arg);
		ft_strdel(&arg);
		info->comma_f = (info->comma_f = 1 && info->error == 0) ? 0 : info->comma_f;
		return (info->end);
	}
	return (i);
}
