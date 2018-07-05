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

/*static void	ft_color_pyr(t_arena *arena, int *tab_color)
{
	int	p;

	p = 0;
	while (p < arena->nb_pyrs)
	{
		arena->tab_pyr[p].color_pyr = tab_color[p];
		p++;
	}
}
*/
void		ft_init_visual(t_arena *arena)
{
	int p;
	int tab_color[7] = {4, 1, 2, 3, 5, 6, 7};

	p = 1;
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
	while (p <= arena->nb_pyrs)
	{
		init_pair(p, tab_color[p - 1], COLOR_BLACK);
		p++;
	}
	//ft_color_pyr(arena, tab_color);
}

void		ft_visual(t_arena *arena)
{
	int i;
	t_proc *ptr_proc;

	i = 0;
	while (i < MEM_SIZE)
	{
		ptr_proc = arena->list_proc;
		if (i != 0 && i % 64 == 0)
			printw("\n");
/*		if (arena->map_pyr[i] != 0)
		{
			attron(COLOR_PAIR(arena->map_pyr[i]));
			printw("%.2hhx ", arena->map[i]);
			attroff(COLOR_PAIR(arena->map_pyr[i]));
		}
*/
/*		while (ptr_proc)
		{
			if (i == ptr_proc->pc_act)
			{
				attron(COLOR_PAIR(1));
				printw("%.2hhx ", arena->map[i]);
				attroff(COLOR_PAIR(1));
			}
*/
			else
				printw("%.2hhx ", arena->map[i]);
			ptr_proc = ptr_proc->next;
		}
		i++;
	}
	refresh();
	getch();
	endwin();
}

