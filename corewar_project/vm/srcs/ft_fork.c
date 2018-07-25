/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:40:04 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/24 18:52:14 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			ft_fork(t_arena *arena, t_proc *proc)
{
	int		direct;
	int		index;
	t_proc	*proc_fork;

	direct = (int)ft_read_memory(arena->map, 1, 2);
	ft_index_idxmod(&index, direct, proc->pc_act);
	printf("%d\n", index);
	ft_create_proc(arena, proc, index);
	proc_fork = arena->list_proc;
	if (proc_fork->opcode_valid == 1)
		proc_fork->nb_cycle_before_op--;
	else
		ft_move_process(arena->map_process, proc_fork, proc_fork->ocp);
	//ft_assert("",arena);
}

