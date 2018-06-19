/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_vm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:55:30 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/19 17:08:34 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			ft_check_magic(char *line)
{
	int magic;

	magic = (int)(ft_convert_nbr(line, 4));
	if (magic != COREWAR_EXEC_MAGIC)
		ft_error_vm(1, "Error : Wrong magic number : ", "", magic);
}

int				ft_parse_vm(char *line, t_arena *arena, int pyr_nbr)
{
	(void)pyr_nbr;
	(void)arena;
	//ft_pyr_name(arena);
	ft_check_magic(line);
	return (0);
}

