/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:22:39 by srossi            #+#    #+#             */
/*   Updated: 2018/07/19 13:32:18 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_find_index_arg(char *arg)
{
	int index;

	index = 0;
	while (index < 17)
	{
		if (ft_strequ(arg, op_tab[index].name))
			break ;
		index++;
	}
	return (index);
}
