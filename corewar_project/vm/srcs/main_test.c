/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:43:33 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/18 15:05:19 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_print_test(char *line)
{
	int i = 0;

	while (i < COR_SIZE_MAX + 5)
	{
		ft_printf("%x ", line[i]);
		i++;
	}
	putchar('\n');
}



/*int main()
{
	return (0);
}*/
