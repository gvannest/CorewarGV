
#include "asm.h"






char *ft_whitesp(t_asm *info, char *line)
{
	int i;

	i = 0;
	if (info->name_f < 0 || info->quote == 1 || info->comment_f < 0)
		return (line);
	while (line[i] && ft_is_space(line[i]))
		++i;
	return (&line[i]);
}

void	ft_parse_cmd(t_asm *info, char *line)
{
	line  = ft_whitesp(info, line);
	if ((info->name_f != -1) && ((ft_strnequ(line, COMMENT_CMD_STRING, 8)
					&& info->comment_f == 0) || info->comment_f < 0))
	{
		info->quote = (info->comment_f == 0) ? 0 : info->quote;
		ft_comment(&(*info), line);
		if (info->comment_f < 0 && info->quote != 2)
			info->comment[ft_strlen(info->comment)] = '\n';
	}
	else if ((info->comment_f != -1) && ((ft_strnequ(line, NAME_CMD_STRING, 5)
					&& info->name_f == 0) || info->name_f < 0))
	{
		info->quote = (info->name_f == 0) ? 0 : info->quote;
		ft_name(&(*info), line);
		if (info->name_f < 0 && info->quote != 2 && ft_strlen(line) != 0)
		{
			info->name[ft_strlen(info->name)] = '\n';
		}
	}
}
