/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:53:58 by gvannest          #+#    #+#             */
/*   Updated: 2018/08/03 09:54:18 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void		ft_winner_visu(t_player *tab_pyr, int nb_pyrs, t_corvisu *visual, int winner)
{
	int c;

	(void)winner;
	(void)tab_pyr;
	(void)nb_pyrs;
	(void)visual;
	c = getch();
	while (c != 27)
		c = getch();
	endwin();
}
