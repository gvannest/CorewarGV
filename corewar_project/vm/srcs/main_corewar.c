/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:54:27 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/20 18:20:06 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_open_cor(t_arena *arena, char **argv, int i)
{
	int			fd;
	char		line[COR_SIZE_MAX + 1];
	int			ret;
	static int	tab_pyr_i = 0;

	ft_bzero(line, sizeof(char) * COR_SIZE_MAX + 5);
	if ((fd = open(argv[i], O_RDONLY)) < 0)
		ft_error_vm(0, "Error : File opening failed\n", argv[i], 0);
	if ((ret = read(fd, line, COR_SIZE_MAX)) < 0)
		ft_error_vm(0, "Error : File reading failed\n", argv[i], 0);
	line[COR_SIZE_MAX] = '\0';
	if (close(fd) < 0)
		ft_error_vm(0, "Error : File closing failed\n", argv[i], 0);
	ft_parse_vm1(line, arena, argv[i], tab_pyr_i);
	tab_pyr_i++;
}

int				main(int argc, char **argv)
{
	t_arena	arena;
	int		i;

	i = 0;
	ft_bzero(&arena, sizeof(arena));
	ft_param(argc, argv, &arena);
	while (i < argc)
	{
		if (ft_strstr(argv[i], ".cor"))
			ft_open_cor(&arena, argv, i);
		i++;
	}
	ft_assert("", &arena);
	//ft_fill_arena(&arena);
	return (0);
}

