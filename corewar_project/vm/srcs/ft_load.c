/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:31:06 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/24 13:11:12 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_load(t_arena *arena, t_proc *proc)
{
	int k;

	if (!(ft_get_param(arena, proc, proc->pc_act, 0)))
		return;
	if (!ft_check_ocp(proc->tab_param, "di", "r", ""))
		return;
	if (proc->tab_param[0].type == 'd')
		proc->reg[proc->tab_param[1].value - 1] = proc->tab_param[0].value;
	else if (proc->tab_param[0].type == 'i')
	{
		ft_index_idxmod(&k, proc->tab_param[0].value, proc->pc_act);
		proc->reg[proc->tab_param[1].value - 1] = (int)ft_read_memory(arena->map, k, 4);
	}
	(proc->reg[proc->tab_param[2].value - 1] == 0 ? proc->carry = 1 : 0);
}
