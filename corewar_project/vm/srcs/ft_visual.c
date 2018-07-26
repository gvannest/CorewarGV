/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:57 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/25 14:24:36 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, ACS_VLINE, ACS_HLINE);
	wrefresh(local_win);
	return (local_win);
}

static void		ft_init_color()
{
	start_color();
	if(has_colors() == FALSE)
	{
		endwin();
		ft_error_vm(0, "Your terminal does not support color", "", 0);
	}
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_GREEN);
	init_pair(9, COLOR_BLACK, COLOR_RED);
	init_pair(10, COLOR_BLACK, COLOR_BLUE);
	init_pair(11, COLOR_BLACK, COLOR_YELLOW);
	init_pair(12, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(13, COLOR_BLACK, COLOR_CYAN);
	init_pair(14, COLOR_BLACK, COLOR_WHITE);
}

void		ft_init_visual(t_corvisu *visual)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	ft_init_color();
	refresh();
	visual->win_arena = create_newwin(64 + 2, 65 * 3 + 2, 0, 0);
	visual->win_info_game = create_newwin(15, 65 * 3 + 2, 64 + 2, 0);
	visual->win_info_pyrs = create_newwin(64 + 2, 60, 0, 65 * 3 + 2);
	curs_set(0);
}

void		ft_visual(t_arena *arena, t_corvisu *visual)
{
	int i;

	i = 0;
	ft_info_fix(arena->tab_pyr, arena->nb_pyrs, visual);
	while (i < MEM_SIZE)
	{
		if (arena->map_process[i] != 0)
			ft_is_proc(visual, arena->map_pyr[i], arena->map[i], i);
		else
			ft_is_not_proc(visual, arena->map_pyr[i], arena->map[i], i);
		ft_info_game(arena, visual);
		ft_info_player(arena->tab_pyr, arena->nb_pyrs, visual);
		i++;
	}
	wrefresh(visual->win_arena);
	wrefresh(visual->win_info_game);
	wrefresh(visual->win_info_pyrs);
	getch();
}

