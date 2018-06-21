/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:30:07 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/21 15:24:27 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		ft_isnum(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static	int		ft_check_param(char **argv, int argc, int i, t_arena *arena)
{
	if (ft_strcmp(argv[i], "-n") == 0)
	{
		if (i < (argc - 2) && ft_isnum(argv[i + 1]) &&
			ft_strstr(argv[i + 2], ".cor"))
			return (1);
	}
	else if (ft_strcmp(argv[i], "-dump") == 0)
	{
		if (ft_isnum(argv[i + 1]))
			return (1);
	}
	else if (ft_strcmp(argv[i], "-visual") == 0)
		return (1);
	else if (ft_isnum(argv[i]))
	{
		if (ft_strcmp(argv[i - 1],"-dump") == 0 || (ft_strcmp(argv[i - 1],
			"-n") == 0 && ft_strstr(argv[i + 1], ".cor")))
			return (1);
	}
	else if (ft_strstr(argv[i], ".cor"))
	{
		arena->nb_pyrs++;
		return (1);
	}
	return (0);
}

static void			ft_upload_num_player(char **argv, int i, t_arena *arena)
{
	static int	k = 0;
	int			p;
	int			n;

	p = 0;
	n = ft_atoi(argv[i + 1]);
	if (n == 0)
		ft_error_vm(1, "Error : Player cannot get the number 0", "", 0);
	while (p < k)
	{
		if (arena->tab_pyr[p].pyr_nbr == n)
			ft_error_vm(1, "Error : two players with same number", "", 0);
		p++;
	}
	if (k == MAX_PLAYERS)
		ft_error_vm(3, "Error : wrong number of players", "", arena->nb_pyrs);
	arena->tab_pyr[k].pyr_nbr = n;
	k++;
}


void			ft_param(int argc, char **argv, t_arena *arena)
{
	int		i;

	i = 1;
	if (argc == 1 || argc > MAX_ARG)
		ft_error_vm(1, "Wrong number of arguments", "", 0);
	while (i < argc)
	{
		if (!ft_check_param(argv, argc, i, arena))
			ft_error_vm(1, "Error usage : wrong arguments", "", 0);
		if (ft_strcmp(argv[i], "-n") == 0)
			ft_upload_num_player(argv, i, arena);
		i++;
	}
	if (arena->nb_pyrs < 1 || arena->nb_pyrs > 4)
		ft_error_vm(3, "Error : wrong number of players", "", arena->nb_pyrs);
}

