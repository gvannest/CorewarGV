/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:57 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/29 19:08:45 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_visual.h"

static void		ft_init_color(unsigned short nb_players)
{
	int p;
	int tab_color[8] = {0, 4, 1, 2, 3, 5, 6, 7};

	p = 1;
	while (p <= nb_players)
	{
		init_pair(p, tab_color[p], COLOR_BLACK);
		p++;
	}
}

void		ft_init_visual(t_arena *arena)
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	if(has_colors() == FALSE)
	{
		endwin();
		ft_error_vm(0, "Your terminal does not support color", "", 0);
	}
	start_color();
	ft_init_color(arena->nb_pyrs);
}

void		ft_visual(t_arena *arena)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % 64 == 0)
			printw("\n");
		if (arena->map_pyr[i] != 0)
		{
			attron(COLOR_PAIR(arena->map_pyr[i]));
			printw("%.2hhx ", arena->map[i]);
			attroff(COLOR_PAIR(arena->map_pyr[i]));
		}
		i++;
	}
	refresh();
	getch();
	endwin();
}

