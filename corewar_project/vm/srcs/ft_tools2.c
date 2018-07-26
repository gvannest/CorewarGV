/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:12:33 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/25 14:56:33 by gvannest         ###   ########.fr       */
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

void		ft_calc_index(int *k, int value, int pc_act, char flag_idx)
{
	unsigned int	mod;

//	(flag_idx == 1 ? mod = IDX_MOD : mod = MEM_SIZE);
	mod = flag_idx == 1 ? IDX_MOD : MEM_SIZE;
	*k = pc_act + (short int)value % mod;
	(*k < 0 ? *k = *k + MEM_SIZE : *k);
}

