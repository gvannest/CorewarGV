/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                          :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:10:36 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/24 12:13:27 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			ft_ldi(t_arena *arena, t_proc *proc)
{

	int k;
	int i;
	int	tab_tmp[2];

	i = 0;
	if (!(ft_get_param(arena, proc, proc->pc_act, 1)))
		return;
	if (!ft_check_ocp(proc->tab_param, "rdi", "ir", "r"))
		return;
	while (i < 2)
	{
		
