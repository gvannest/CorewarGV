/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_nb_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:57:11 by srossi            #+#    #+#             */
/*   Updated: 2018/06/21 14:59:19 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strtab_nblines(char **tab)
{
	int	nb_lines;

	nb_lines = 0;
	while (tab[nb_lines])
		nb_lines++;
	return (nb_lines);
}