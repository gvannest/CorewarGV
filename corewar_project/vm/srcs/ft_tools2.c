/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:12:33 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/20 13:58:57 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ft_isnum(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void		ft_update_map_pyr(int *map_pyr, int pc_act, int start, size_t k)
{
	size_t i;

	i = 0;
	while (i < k)
	{
		map_pyr[(start + i) % MEM_SIZE] = map_pyr[pc_act];
		i++;
	}
}

int			ft_verif_reg(t_proc *proc)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (proc->tab_param[i].type == 'r' &&
			(proc->tab_param[i].value < 1 || proc->tab_param[i].value > 16))
			return (0);
		i++;
	}
	return (1);
}

void		ft_index_idxmod(int *k, int value, int pc_act)
{
	*k = pc_act + (short int)value % IDX_MOD;
	(*k < 0 ? *k = *k + MEM_SIZE : *k);
}
