/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:02:34 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/24 12:11:33 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned long	ft_read_memory(char *map, int start, size_t k)
{
	unsigned short		i;
	unsigned long long	res;

	i = 0;
	res = 0;
	while (i < k)
	{
		res = res | (map[(start + i) % MEM_SIZE] & 0xff) << 8 * (k - 1 - i);
		i++;
	}
	return (res);
}

void			ft_write_memory(char *map, unsigned int v, int start, size_t k)
{
	unsigned short		i;

	i = 0;
	while (i < k)
	{
		map[(start + i) % MEM_SIZE] = v >> (8 * (k - 1 - i));
		i++;
	}
}

static int	ft_verif_reg(t_param *tab)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (tab[i].type == 'r' && (tab[i].value < 1 || tab[i].value > 16))
			return (0);
		i++;
	}
	return (1);
}

int			ft_check_ocp(t_param *tab, char *p1, char *p2, char *p3)
{
	int i;
	static int cpt = 1;

	i = 0;
	cpt++;
	if (!ft_strchr(p1, tab[0].type))
		return (0);
	if (!ft_strchr(p2, tab[1].type))
		return (0);
	if (!ft_strchr(p3, tab[2].type))
		return (0);
	if (!ft_verif_reg(tab))
		return (0);
	return (1);
}

