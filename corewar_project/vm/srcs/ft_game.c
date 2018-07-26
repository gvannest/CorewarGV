/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:59:16 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/25 13:54:45 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_game(t_arena *arena, t_corvisu *visual, char v)
{
	if (v == 1)
		ft_init_visual(visual);
	while (arena->nb_live_proc > 0 && arena->cycle_to_die > 0)
	{
		while (arena->nb_cycle_current < arena->cycle_to_die)
		{
			if (v == 1)
				ft_visual(arena, visual);
			ft_one_cycle(arena, arena->list_proc);
			arena->nb_cycle++;
			arena->nb_cycle_current++;
			if (arena->dump_f == 1 && arena->nb_cycle == (unsigned int)arena->dump_nb)
				ft_dump_mem(arena);
		}
		ft_check_cycle(arena);
		ft_reinit_cycle(arena, arena->list_proc);
	}
	getch();
	endwin();
}
