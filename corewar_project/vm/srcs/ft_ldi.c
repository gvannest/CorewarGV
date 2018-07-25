/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                          :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:10:36 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/24 17:01:39 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_loop_ldi(char *map, int *tab_tmp, int i, t_proc *proc)
{
	int k;

	if (proc->tab_param[i].type == 'r')
		tab_tmp[i] = proc->reg[proc->tab_param[i].value - 1];
	else if (proc->tab_param[i].type == 'd')
		tab_tmp[i] = proc->tab_param[i].value;
	else if (proc->tab_param[i].type == 'i')
	{
		ft_index_idxmod(&k, proc->tab_param[i].value, proc->pc_act);
		tab_tmp[i] = (int)ft_read_memory(map, k, 4);
	}
}

void			ft_ldi(t_arena *arena, t_proc *proc)
{
	int res;
	int i;
	int	tab_tmp[2];

	i = 0;
	if (!(ft_get_param(arena, proc, proc->pc_act, 1)))
		return;
	if (!ft_check_ocp(proc->tab_param, "rdi", "dr", "r"))
		return;
	while (i < 2)
	{
		ft_loop_ldi(arena->map, tab_tmp, i, proc);
		i++;
	}
	ft_index_idxmod(&res, tab_tmp[0] + tab_tmp[1], proc->pc_act);
	proc->reg[proc->tab_param[2].value - 1] = (int)ft_read_memory(arena->map, res, 4);
	(res == 0 ? proc->carry = 1 : 0);
}
