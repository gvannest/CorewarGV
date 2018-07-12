/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:31:06 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/12 18:23:24 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_load(t_arena *arena, t_proc *proc)
{
	ft_get_param(arena, proc, proc->pc_act, 0);
	if (proc->tab_param[1].value < 1 || proc->tab_param[1].value > 16)
		return;
	if (proc->tab_param[0].type == 'd')
		proc->reg[proc->tab_param[1].value - 1] = proc->tab_param[0].value;
	else if (proc->tab_param[0].type == 'i')
		proc->reg[proc->tab_param[1].value - 1] =
		arena->map[(short)(proc->pc_act + proc->tab_param[0].value) % IDX_MOD];
	if (proc->reg[proc->tab_param[1].value - 1] == 0)
		proc->carry = 1;
	ft_assert("", arena);
}
