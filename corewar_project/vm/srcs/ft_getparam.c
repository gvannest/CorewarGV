/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getparam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 11:25:30 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/24 11:44:38 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


static int		ft_get_param_value(char *map, t_param *tab, int pc)
{
	int i;

	i = 0;
	tab[0].value = (int)ft_read_memory(map, pc + 2, tab[0].size);
	tab[1].value = (int)ft_read_memory(map, pc + 2 + tab[0].size,
			tab[1].size);
	tab[2].value = (int)ft_read_memory(map, pc + 2 + tab[0].size + tab[1].size,
			tab[2].size);
	while (i < 3)
	{
		if (tab[i].type == 'r' && (tab[i].value < 1 || tab[i].value > 16))
			return (0);
		i++;
	}
	return (1);
}

int			ft_get_param(t_arena *arena, t_proc *proc, int pc, char dir_size)
{
	int		i;

	i = 0;
	proc->ocp = (char)ft_read_memory(arena->map, pc + 1, 1);
	while (i < 3)
	{
		if ((proc->ocp >> (6 - 2 * i) & 0x03) == 1)
		{
			proc->tab_param[i].type = 'r';
			proc->tab_param[i].size = 1;
		}
		else if ((proc->ocp >> (6 - 2 * i) & 0x03) == 2)
		{
			proc->tab_param[i].type = 'd';
			proc->tab_param[i].size = 4 - 2 * dir_size;
		}
		else if ((proc->ocp >> (6 - 2 * i) & 0x03) == 3)
		{
			proc->tab_param[i].type = 'i';
			proc->tab_param[i].size = 2;
		}
		i++;
	}
	if (!(ft_get_param_value(arena->map, proc->tab_param, pc)))
		return (0);
	return (1);
}
