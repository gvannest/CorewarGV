/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:02:34 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/19 14:21:01 by gvannest         ###   ########.fr       */
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
