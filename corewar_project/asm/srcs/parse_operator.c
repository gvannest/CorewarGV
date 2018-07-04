
#include "asm.h"
/*
#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','
#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"
*/
static int	ft_split_word(t_asm *info, char *line, int i)
{
	char	*arg;

	arg = 0;
	info->start = i;
	//Verifier le char LABEL_CHARS
		while (line[i] && (ft_strchr(LABEL_CHARS, line[i]) || ft_is_othchr(line[i])) && !ft_is_sep(line[i]) && line[i] != '\n') //line[i] && !ft_is_space(line[i]) && !ft_is_sep(line[i]))
		{
			if (line[i] == COMMENT_CHAR)
			{
				info->comment_char = 1;
				return (i);
			}
			++i;
		}
		if (i != info->start)// && line[info->start] != '\0')
		{
			info->end = i;
			arg = ft_strsub(line, info->start, info->end - info->start);
			//ft_token_add(&(*info), &(*arg));
			ft_printf("->%s<-\t\t\t", arg);
	//		ft_printf("start=%d, end=%d \n", info->start, info->end);
			ft_strdel(&arg);
			return (info->end);
		}
	return (i);
}

void	ft_parse_op(t_asm *info, char *line)
{
	int i;

//	printf("check ft_parse_op\n");
	info->end = 0;
	info->comment_char = 0;
	info->start = 0;
	i = 0;
	while (line[i])
	{
		 if (line[i] && !ft_is_space(line[i]))
		 {
			// ft_printf("char->%c<-\n", line[i]);
			i = ft_split_word(&(*info), line, i);
		 }
		 if (info->comment_char == 1)
			 break ;
	//	 printf("i=%d ->%c<-\n", i, line[i]);
		 ++i;
	}
}
