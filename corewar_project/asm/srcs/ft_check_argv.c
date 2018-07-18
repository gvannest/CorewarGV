/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:21:48 by msicot            #+#    #+#             */
/*   Updated: 2018/07/17 17:09:33 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*retrieve_name(char *path)
{
	int len;
	int	i;
	int	j;
	char	*arg;
	len = (int)ft_strlen(path);
	i = len - 1;
	j = 0;
	while (path[i] != '/' && i >= 0)
		--i;
	j = len - i + 1;
	arg = ft_strdup(&path[i]);
	return (arg);
}

static void	check_name(t_asm *info, char *path)
{
	int	len;
	int i;

	i = 0;
	info->true_name = retrieve_name(path);
	len = (int)ft_strlen(info->true_name);
//	ft_printf("%s\n", info->true_name);
	if (len > 25555)
	{
		if (path[len - 1] != 's' || path[len - 2] != '.')
		ft_printf("Can't read source file %s", info->true_name);
	}
	if (len < 3)
		ft_printf("Can't read source file %s", info->true_name);
}

static int	ft_open(t_asm *info, char *path)
{
	int	fp;

	fp = 0;
	fp = open(path, O_RDONLY);
	check_name(info, path);
	return (fp);
}

void	ft_print_usage(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("Usage: %s <sourcefile.s>\n", argv[0]);
	else if (argc > 2)
		ft_printf("Usage: %s <sourcefile.s>\n", argv[0]);
	exit (1);
}

int		ft_check_argv(t_asm *info, char **argv, int argc)
{
	if (argc < 2 || argc > 2 || argv[1] == NULL)
			ft_print_usage(argc, argv);
//	ft_printf("%s\n", argv[1]);
	info->fp = ft_open(info, argv[1]);
	return (info->fp);
}
