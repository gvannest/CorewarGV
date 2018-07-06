/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:22:10 by msicot            #+#    #+#             */
/*   Updated: 2018/07/06 13:59:46 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_info(t_asm *info)
{
	info->last_opcode = -1;
	info->err_pos = -1;
}

int	ft_open(char *path)
{
	int	fp;

	fp = 0;
	fp = open(path, O_RDONLY);
	return (fp);
}

int	main(int argc, char **argv)
{
	(void) argc;
	t_asm	info;
	(void) argv;

	ft_bzero(&info, sizeof(t_asm));
	init_info(&info);
//	ft_test_params();
//	ft_test_label();
//	if (argc < 2 || argc > 2 || argv[1] == NULL)
//		perror("Error");
//	else if ((info.fp = ft_open(argv[1])) == 0)
//		return (0);
//	printf("main\n");
//	ft_gnl(&info);
//	if (info.error != 0)
//		ft_printf("Error found");
//	if (argc < 2 || argc > 2 || argv[1] == NULL)
//		perror("Error");
//	else if ((info.fp = ft_open(argv[1])) == 0)
//		return (0);
//	ft_tests_syntax();
//	printf("test display\n");
	ft_display(&info);
	return (0);
}
