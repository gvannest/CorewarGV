/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:31:06 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/26 14:59:56 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_ldandlld(t_arena *arena, t_proc *proc, char flag_idx)
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
		ft_calc_index(&k, proc->tab_param[0].value, proc->pc_act, flag_idx);
		proc->reg[proc->tab_param[1].value - 1] = (int)ft_read_memory(arena->map, k, REG_SIZE);
	}
	(proc->reg[proc->tab_param[2].value - 1] == 0 ? proc->carry = 1 : 0);
}

void		ft_load(t_arena *arena, t_proc *proc)
{
	ft_ldandlld(arena, proc, 1);
}

void		ft_lld(t_arena *arena, t_proc *proc)
{
	ft_ldandlld(arena, proc, 0);
}
