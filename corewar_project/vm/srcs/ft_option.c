/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:30:07 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/19 18:15:08 by gvannest         ###   ########.fr       */
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

void			ft_param(int argc, char **argv, t_arena *arena)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!ft_check_param(argv, argc, i, arena))
			ft_error_vm(1, "Error usage : wrong arguments\n", "", 0);
		i++;
	}
	if (arena->nb_pyrs < 1 || arena->nb_pyrs > 4)
		ft_error_vm(3, "Error : wrong number of players\n", "", arena->nb_pyrs);
}

