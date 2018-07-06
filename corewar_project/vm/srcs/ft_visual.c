/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:57 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/06 11:59:28 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_visual.h"

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, startx, starty);
	wrefresh(local_win);
	return (local_win);
}

static void		ft_init_color(unsigned short nb_players)
{
	int p;
	int tab_color[8] = {0, 4, 1, 2, 3, 5, 6, 7};

	p = 1;
	if(has_colors() == FALSE)
	{
		endwin();
		ft_error_vm(0, "Your terminal does not support color", "", 0);
	}
	while (p <= nb_players)
	{
		init_pair(p, tab_color[p], COLOR_BLACK);
		p++;
	}
}

void		ft_init_visual(t_arena *arena, t_corvisu *visual)
{
	int row;
	int col;

	(void)visual;
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	ft_init_color(arena->nb_pyrs);
	getmaxyx(stdscr, row, col);
	printw("%d / %d\n", row, col);
	//visual->win_arena = create_newwin(2 * row / 3, col, 0, 0);
	//visual->win_info_game = create_newwin(row / 5, col / 5, (2 / 3 + 1 / 15) * row, col / 5);
	//visual->win_arena = create_newwin(row / 5, col / 5, (2 / 3 + 1 / 15 * row), 3 * col / 5);
	getch();
	endwin();
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

