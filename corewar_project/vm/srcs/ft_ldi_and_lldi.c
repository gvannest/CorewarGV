/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                          :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:10:36 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/26 14:04:09 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_loop_ldi(char *map, int *tab_tmp, t_proc *proc, char flag_idx)
{
	int k;
	int i;

	i = 0;
	while (i < 2)
	{
		if (proc->tab_param[i].type == 'r')
			tab_tmp[i] = proc->reg[proc->tab_param[i].value - 1];
		else if (proc->tab_param[i].type == 'd')
			tab_tmp[i] = proc->tab_param[i].value;
		else if (proc->tab_param[i].type == 'i')
		{
			ft_calc_index(&k, proc->tab_param[i].value, proc->pc_act, flag_idx);
			tab_tmp[i] = (int)ft_read_memory(map, k, REG_SIZE);
		}
		i++;
	}
}

static void			ft_ldi_and_lldi(t_arena *arena, t_proc *proc, char flag_idx)
{
	int res;
	int	tab_tmp[2];

	if (!(ft_get_param(arena, proc, proc->pc_act, 1)))
		return;
	if (!ft_check_ocp(proc->tab_param, "rdi", "dr", "r"))
		return;
	ft_loop_ldi(arena->map, tab_tmp, proc, flag_idx);
	ft_calc_index(&res, tab_tmp[0] + tab_tmp[1], proc->pc_act, flag_idx);
	proc->reg[proc->tab_param[2].value - 1] = (int)ft_read_memory(arena->map, res, REG_SIZE);
	(res == 0 ? proc->carry = 1 : 0);
}

void			ft_ldi(t_arena *arena, t_proc *proc)
{
	ft_ldi_and_lldi(arena, proc, 1);
}

void			ft_lldi(t_arena *arena, t_proc *proc)
{
	ft_ldi_and_lldi(arena, proc, 0);
}
