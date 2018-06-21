/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:47:09 by msicot            #+#    #+#             */
/*   Updated: 2018/06/14 13:53:45 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
void	parsing_error(t_asm *info, int pos, char *line)
{
	if (info->error == 1)
	{
	ft_printf("Syntax error at token [TOKEN][%0d:00]\n", info->line_nb);
	}
}

void	ft_error(int a)
{
	if (a == 1)
	{
		perror("Error");
//		exit(0);
	}
	else
		return ;
}

