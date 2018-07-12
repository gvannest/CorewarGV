/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_corewar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:26:52 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/12 15:31:08 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_free_listproc(t_proc *begin_list)
{
	while(begin_list)
	{
		free(begin_list);
		begin_list = begin_list->next;
	}
}
