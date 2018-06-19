/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:43:33 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/19 14:18:02 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_print_test(char *line)
{
	int i = 0;

	printf(" ");
	while (i < COR_SIZE_MAX + 5)
	{
		printf("%.2hhx", line[i]);
		i++;
		if (i % 16 == 0 & i != 0)
			printf("\n");
		if (i % 2 == 0)
			printf(" ");
	}
	putchar('\n');
	putchar('\n');
}



/*int main()
{
	return (0);
}*/
