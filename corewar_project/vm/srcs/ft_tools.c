/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:02:34 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/10 17:53:12 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned long long		ft_convert_nbr(char *str, size_t k)
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

void					ft_write_memory(char *str, unsigned int v, size_t k)
{
	unsigned short		i;

	i = 0;
	while (i < k)
	{
		str[i] = v >> (8 * (k - 1 - i));
		i++;
	}
}

int						ft_isnum(char *str)
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


