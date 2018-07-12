/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <gvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:54:27 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/12 18:17:52 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_open_cor(t_arena *arena, char **argv, int argc, int i)
{
	int			fd;
	char		line[COR_SIZE_MAX + 1];
	int			ret;
	static int	tab_pyr_i = 0;

	while (i < argc)
	{
		if (ft_strstr(argv[i], ".cor"))
		{
			ft_bzero(line, sizeof(char) * COR_SIZE_MAX + 5);
			if ((fd = open(argv[i], O_RDONLY)) < 0)
				ft_error_vm(0, "Error : File opening failed", argv[i], 0);
			if ((ret = read(fd, line, COR_SIZE_MAX)) < 0)
				ft_error_vm(0, "Error : File reading failed", argv[i], 0);
			line[COR_SIZE_MAX] = '\0';
			if (close(fd) < 0)
				ft_error_vm(0, "Error : File closing failed", argv[i], 0);
			ft_parse_vm1(line, arena, argv[i], tab_pyr_i);
			tab_pyr_i++;
		}
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_arena			arena;
	t_corvisu		visual;
	int				i;
	char			v;

	i = 0;
	ft_bzero(&arena, sizeof(arena));
	v = ft_arguments(argc, argv, &arena);
	ft_open_cor(&arena, argv, argc, i);
	ft_fill_game(&arena);
	ft_game(&arena, &visual, v);
	ft_assert("", &arena);
	return (0);
}

