/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:59:32 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/20 15:56:31 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			ft_sub(t_arena *arena, t_proc *proc)
{
	int	tab_tmp[2];

	if (!(ft_get_param(arena, proc, proc->pc_act, 0)))
		return;
	if (!(ft_verif_reg(proc)))
		return;
	tab_tmp[0] = proc->reg[proc->tab_param[0].value - 1];
	tab_tmp[1] = proc->reg[proc->tab_param[1].value - 1];
	proc->reg[proc->tab_param[2].value - 1] = tab_tmp[0] - tab_tmp[1];
	(proc->reg[proc->tab_param[2].value - 1] == 0 ? proc->carry = 1 : 0);
}
