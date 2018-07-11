/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:24:08 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/10 16:18:41 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_is_proc(t_corvisu *visual, int pyr_idx, char inst, int i)
{
	int		c;

	if (pyr_idx != 0)
		c = 7 + pyr_idx;
	else
		c = 14;
	wattron(visual->win_arena, COLOR_PAIR(c));
	mvwprintw(visual->win_arena, i / 64 + 1, (i % 64 + 1) * 3, "%.2hhx", inst);
	wattroff(visual->win_arena, COLOR_PAIR(c));
}

void		ft_is_not_proc(t_corvisu *visual, int pyr_idx, char inst, int i)
{

	if (pyr_idx != 0)
	{
		wattron(visual->win_arena, COLOR_PAIR(pyr_idx));
		mvwprintw(visual->win_arena, i / 64 + 1, (i % 64 + 1) * 3, "%.2hhx", inst);
		wattroff(visual->win_arena, COLOR_PAIR(pyr_idx));
	}
	else
		mvwprintw(visual->win_arena, i / 64 + 1, (i % 64 + 1) * 3, "%.2hhx", inst);
}

void		ft_info_fix(t_player *tab_pyr, int nb_pyrs, t_corvisu *visual)
{
	int p;

	p = 0;
	wattron(visual->win_info_game, A_BOLD);
	mvwprintw(visual->win_info_game, 1, 2,  "Cycle to die   : ");
	mvwprintw(visual->win_info_game, 3, 2,  "Current cycle  : ");
	mvwprintw(visual->win_info_game, 5, 2,  "Nombre de live current cycle : ");
	mvwprintw(visual->win_info_game, 7, 2,  "Nombre de live total : ");
	mvwprintw(visual->win_info_game, 9, 2,  "Nombre de processus en vie : ");
	mvwprintw(visual->win_info_game, 1, 60,  "Dernier joueur live : ");
	wattron(visual->win_info_game, A_BOLD);
	while (p < nb_pyrs)
	{
		wattron(visual->win_info_pyrs, COLOR_PAIR(p + 1));
		mvwprintw(visual->win_info_pyrs, 1 + 10 * p, 2, "Player %d", tab_pyr[p].pyr_nbr);
		wattroff(visual->win_info_pyrs, COLOR_PAIR(p + 1));
		mvwprintw(visual->win_info_pyrs, 10 * p + 3, 5, "Nombre de live : ", tab_pyr[p].pyr_nbr);
		p++;
	}
}

void		ft_info_game(t_arena *arena, t_corvisu *visual)
{
	mvwprintw(visual->win_info_game, 1, 19,  "%6d", arena->cycle_to_die);
	mvwprintw(visual->win_info_game, 3, 19,  "%6d", arena->nb_cycle_current);
	mvwprintw(visual->win_info_game, 5, 32,  "%6d", arena->nb_live_currt);
	mvwprintw(visual->win_info_game, 7, 32,  "%6d", arena->nb_live_tot);
	mvwprintw(visual->win_info_game, 9, 32,  "%6d", arena->nb_live_proc);
	mvwprintw(visual->win_info_game, 1, 85,  "%2d", arena->last_live_pyr);
}

void		ft_info_player(t_player *tab_pyr, int nb_pyrs, t_corvisu *visual)
{
	int p;

	p = 0;
	while (p < nb_pyrs)
	{
		mvwprintw(visual->win_info_pyrs, 10 * p + 3, 20, "%6d", tab_pyr[p].pyr_nb_live);
		p++;
	}
}
