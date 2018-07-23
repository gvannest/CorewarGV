/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:56:38 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/23 10:32:53 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			ft_zjmp(t_arena *arena, t_proc *proc)
{
	int k;
	int pos_proc;
	int value;

	proc->ocp = -1;
	if (proc->carry == 1)
	{
		pos_proc = arena->map_process[proc->pc_act];
		arena->map_process[proc->pc_act] = 0;
		value = (int)ft_read_memory(arena->map, proc->pc_act + 1, 2);
		ft_index_idxmod(&k, value, 0);
		proc->pc_act = (proc->pc_act + k) % MEM_SIZE;
		proc->jump = 1;
		arena->map_process[proc->pc_act] = pos_proc;
	}
}

