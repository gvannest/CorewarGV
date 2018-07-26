/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:56:38 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/25 14:53:03 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			ft_zjmp(t_arena *arena, t_proc *proc)
{
	int k;
	int value;

	proc->ocp = -1;
	if (proc->carry == 1)
	{
		arena->map_process[proc->pc_act] = 0;
		value = (int)ft_read_memory(arena->map, proc->pc_act + 1, 2);
		ft_calc_index(&k, value, proc->pc_act, 1);
		proc->pc_act = k;
		proc->jump = 1;
		arena->map_process[proc->pc_act] = 1;
	}
}

