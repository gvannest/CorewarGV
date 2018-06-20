/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:43:33 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/20 18:21:02 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*static void	ft_print_cor(char *line)
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
*/
static void		ft_print_champ(t_arena *arena)
{
	unsigned short i;

	i = 0;
	while(i < (arena->nb_pyrs))
	{
		printf("%d /", arena->tab_pyr[i].pyr_nbr);
		printf("%s /", arena->tab_pyr[i].pyr_name);
		printf("%s /", arena->tab_pyr[i].comment);
		printf("%#x / %d\n", arena->tab_pyr[i].nb_instructions, arena->tab_pyr[i].nb_instructions);
		i++;
	}
}

void		ft_assert(char *line, t_arena *arena)
{
	(void)line;
	//ft_print_cor(line);
	ft_print_champ(arena);
}

