/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:52:55 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/26 15:07:22 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_aff(t_arena *arena, t_proc *proc)
{
	unsigned char c;

	if (!(ft_get_param(arena, proc, proc->pc_act, 0)))
		return;
	if (!ft_check_ocp(proc->tab_param, "r", "", ""))
		return;
	c = (unsigned char)(proc->reg[proc->tab_param[0].value - 1]);
	ft_putchar(c);
	(c == 0 ? proc->carry = 1 : 0);
}
