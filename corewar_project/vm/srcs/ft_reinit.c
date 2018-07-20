/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:56:20 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/20 15:08:33 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_reinit_cycle(t_arena *arena, t_proc *proc)
{
	arena->nb_cycle_current = 0;
	arena->nb_live_currt = 0;
	while (proc)
	{
		proc->nb_live_curr_cycle = 0;
		proc = proc->next;
	}
}

void		ft_reinit_param(t_proc *proc)
{
	int i;

	i = 0;
	while (i < 3)
	{
		proc->tab_param[i].value = 0;
		proc->tab_param[i].size = 0;
		proc->tab_param[i].type = 0;
		i++;
	}
	proc->ocp = 0;
	proc->jump = 0;
	proc = proc->next;
}
