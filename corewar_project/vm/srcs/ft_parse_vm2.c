/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_vm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:56:31 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/20 18:12:00 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_get_comment(char *line, t_arena *arena, char *cor, int i)
{
	int a;

	a = 0;
	while (a < COMMENT_LENGTH + 1)
	{
		arena->tab_pyr[i].comment[a] = line[a];
		a++;
	}
	if (line[a])
		ft_error_vm(4, "Error : comment is too long\n", cor, 2);
}

void			ft_parse_vm2(char *line, t_arena *arena, char *cor, int i)
{
	ft_get_comment(line + 3 * 4 + PROG_NAME_LENGTH, arena, cor, i);
}
