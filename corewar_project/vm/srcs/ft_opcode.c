/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opcode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:07:44 by msicot            #+#    #+#             */
/*   Updated: 2018/08/28 09:08:12 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_check_opcode(t_proc *proc)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (proc->opcode_act == op_tab[i].opcode)
		{
			proc->opcode_valid = 1;
			proc->nb_cycle_before_op = op_tab[i].nb_cycles;
			return ;
		}
		else
			proc->opcode_valid = 0;
		i++;
	}
}

void		ft_next_opcode(t_arena *arena, t_proc *proc)
{
	proc->opcode_act = arena->map[proc->pc_act];
	ft_check_opcode(proc);
}
