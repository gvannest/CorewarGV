/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:32:14 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/24 17:28:30 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_loop_sti(char *map, int *tab_tmp, int i, t_proc *proc)
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

void			ft_sti(t_arena *arena, t_proc *proc)
{
	int i;
	int res;
	int	tab_tmp[3];

	i = 1;
	if (!(ft_get_param(arena, proc, proc->pc_act, 1)))
		return;
	if (!ft_check_ocp(proc->tab_param, "r", "dri", "dr"))
		return;
	while (i < 3)
	{
		ft_loop_sti(arena->map, tab_tmp, i , proc);
		i++;
	}
	ft_index_idxmod(&res, tab_tmp[1] + tab_tmp[2], proc->pc_act);
	ft_write_memory(arena->map, proc->reg[proc->tab_param[0].value - 1], res, 4);
	ft_update_map_pyr(arena->map_pyr, proc->pc_act, res, 4);
	(res == 0 ? proc->carry = 1 : 0);
}
