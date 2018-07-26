/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:08:15 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/26 12:34:17 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_store(t_arena *arena, t_proc *proc)
{
	int k;
	int reg_value;

	if (!(ft_get_param(arena, proc, proc->pc_act, 0)))
		return;
	if (!ft_check_ocp(proc->tab_param, "r", "ir", ""))
		return;
	reg_value = proc->reg[proc->tab_param[0].value - 1];
	if (proc->tab_param[1].type == 'i')
	{
		ft_calc_index(&k, proc->tab_param[1].value, proc->pc_act, 1);
		ft_write_memory(arena->map, reg_value, k, REG_SIZE);
		ft_update_map_pyr(arena->map_pyr, proc->pc_act, k, REG_SIZE);
	}
	if (proc->tab_param[1].type == 'r')
		proc->reg[proc->tab_param[1].value - 1] = reg_value;
	(proc->reg[proc->tab_param[2].value - 1] == 0 ? proc->carry = 1 : 0);
}
