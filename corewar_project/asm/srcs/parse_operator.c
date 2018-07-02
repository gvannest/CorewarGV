
#include "asm.h"

int		ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int		ft_is_sep(char c)
{
	if (c == SEPARATOR_CHAR || c == LABEL_CHAR)
		return (1);
	return (0);
}


static void	ft_split_line(t_asm *info, char *line, int i)
{
	char	*arg;

	arg = NULL;
	info->start = i;
	//Verifier le char LABEL_CHARS
	while (!ft_is_space(line[i]) && !ft_is_sep(line[i]))
	{
		++i;
	}
	if (i != info->start)
	{
		info->end = i;
		arg = ft_strsub(line, info->start, info->end - info->start);
		//ft_token_add(&(*info), &(*arg));
		ft_printf("arg=%s\n", arg);
	}
}

void	ft_parse_op(t_asm *info, char *line)
{
	int i;
	
	info->end = 0;
	info->start = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_is_space(line[i]))
		{
			ft_split_line(&(*info), line, i);
		}
		++i;
	}

	
}
