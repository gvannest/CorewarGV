/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:08:46 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/23 11:28:42 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_loop_andorxor(char *map, int *tab_tmp, int i, t_proc *proc)
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


static void			ft_andorxor(t_arena *arena, t_proc *proc, char ope)
{
	int *res;
	int	i;
	int	tab_tmp[2];

	i = 0;
	if (!(ft_get_param(arena, proc, proc->pc_act, 0)))
		return;
	if (!(ft_verif_reg(proc)))
		return;
	while (i < 2)
	{
		ft_loop_andorxor(arena->map, tab_tmp, i, proc);
		i++;
	}
	res = &(proc->reg[proc->tab_param[2].value - 1]);
	(ope == 'a' ? *res = tab_tmp[0] & tab_tmp[1] : 0);
	(ope == 'o' ? *res = tab_tmp[0] | tab_tmp[1] : 0);
	(ope == 'x' ? *res = tab_tmp[0] ^ tab_tmp[1] : 0);
	(proc->reg[proc->tab_param[2].value - 1] == 0 ? proc->carry = 1 : 0);
}


void			ft_and(t_arena *arena, t_proc *proc)
{
	ft_andorxor(arena, proc, 'a');
}

void			ft_or(t_arena *arena, t_proc *proc)
{
	ft_andorxor(arena, proc, 'o');
}

void			ft_xor(t_arena *arena, t_proc *proc)
{
	ft_andorxor(arena, proc, 'x');
}
