/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:57 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/29 17:16:16 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*void		ft_init_visual(t_arena *arena)
{*/
	

void		ft_visual(t_arena *arena)
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	printw("%s", arena->map);
	refresh();
	getch();
	endwin();
}

