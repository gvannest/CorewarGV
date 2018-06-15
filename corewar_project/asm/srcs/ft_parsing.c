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

void	ft_gnl(int fp)
{
	char	*line;
	//read
	line = 0;
	while (get_next_line(fp, & line) > 0)
	{
		ft_printf("%s\n", line);
		ft_strdel(&line);

	}
	//save
	//parse
}
