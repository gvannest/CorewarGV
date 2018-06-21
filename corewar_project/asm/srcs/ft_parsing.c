/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:54:26 by msicot            #+#    #+#             */
/*   Updated: 2018/06/14 16:49:46 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_line(t_asm *info, char *line, int len)
{
int i; i = len;
	line = ft_strtrim(line);
	if (info->comment_f <= 0 || info->name_f <= 0)
	{
		if (info->name_f < 0 || !ft_strncmp(line, NAME_CMD_STRING, 5))
		{
			ft_parse_name(&(*info), line);
		}
	}
	ft_strdel(&line);
}

void		ft_gnl(t_asm *info)
{
	char	*line;

	//read
	line = 0;
	while (get_next_line(info->fp, &line) > 0 && info->error == 0)
	{
		ft_printf("%s\n", line);
		check_line(&(*info), line, ft_strlen(line));
		ft_strdel(&line);

	}
	//save
	////Error ? 
	if (info->error != 0)
		parsing_error(info);
	//parse
}
