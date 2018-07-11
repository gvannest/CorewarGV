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

void	analyse_separator(t_asm *info, char *line)
{
	if (START = LABEL_CHAR)
	{
		if (info->label_f == 0)
			++info->label;
		else if (info->operator_f == 1 && info->directchr_f > 0)
		{
				++info->nb_labelchr;
		}
	}		
	else if (START == DIRECT_CHAR)
	{

	}
	else if (START == SEPARATOR_CHAR)
	else if (START == COMMENT_CHAR)
	else if (START == '"')
		++info->quote;
	else if (START == LABEL_CHAR)
}

