/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:02:34 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/12 18:23:26 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned long	ft_read_memory(char *str, size_t k)
{
	unsigned short		i;
	unsigned long long	res;

	i = 0;
	res = 0;
	while (i < k)
	{
		res = res | (str[i] & 0xff) << 8 * (k - 1 - i);
		i++;
	}
	return (res);
}

void			ft_write_memory(char *str, unsigned int v, size_t k)
{
	unsigned short		i;

	i = 0;
	while (i < k)
	{
		str[i] = v >> (8 * (k - 1 - i));
		i++;
	}
}

static void		ft_check_ocp(t_arena *arena, char ocp, int pc)
{
	if ((unsigned char)ocp < 0x04 || (unsigned char)ocp > 0xfc)
	{
		ft_free_listproc(arena->list_proc);
		ft_error_vm(7, "Error : Wrong OCP", "Memory spot :", pc + 1);
	}
}

static void		ft_get_param_value(char *map, t_param *tab, int pc)
{
	tab[0].value = (int)ft_read_memory(&map[pc + 2], tab[0].size);
	tab[1].value = (int)ft_read_memory(&map[pc + 2 + tab[0].size],
			tab[1].size);
	tab[2].value = (int)ft_read_memory(&map[pc + 2 + tab[1].size],
			tab[2].size);
}

void			ft_get_param(t_arena *arena, t_proc *proc, int pc, char dir_size)
{
	int		i;

	i = 0;
	proc->ocp = (char)ft_read_memory(&arena->map[pc + 1], 1);
	ft_check_ocp(arena, proc->ocp, pc);
	while (i < 3)
	{
		if ((proc->ocp >> (6 - 2 * i) & 0x03) == 1)
		{
			proc->tab_param[i].type = 'r';
			proc->tab_param[i].size = 1;
		}
		else if ((proc->ocp >> (6 - 2 * i) & 0x03) == 2)
		{
			proc->tab_param[i].type = 'd';
			proc->tab_param[i].size = 4 - 2 * dir_size;
		}
		else if ((proc->ocp >> (6 - 2 * i) & 0x03) == 3)
		{
			proc->tab_param[i].type = 'i';
			proc->tab_param[i].size = 2;
		}
		i++;
	}
	ft_get_param_value(arena->map, proc->tab_param, pc);
}
