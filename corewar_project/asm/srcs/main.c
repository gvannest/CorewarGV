/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:22:10 by msicot            #+#    #+#             */
/*   Updated: 2018/07/13 15:16:52 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_info(t_asm *info)
{
	info->last_opcode = -1;
	info->err_pos = -1;
	info->nb_params = 0;
	info->size = 1;
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
//	ft_token_display_all(info.atoken);
//	printf("Valid syntax ? : %d\n", ft_is_valid_syntax(&info));
//	printf("Valid syntax ? : %d\n", ft_is_valid_syntax(&info));
//	ft_fill_labels(info.atoken);
//	ft_test_params();
//	ft_test_label();
	if (argc < 2 || argc > 2 || argv[1] == NULL)
		exit (1);
	else if ((info.fp = ft_open(argv[1])) < 0)
		return (0);
	printf("main\n");
	ft_gnl(&info);
	printf("gnl done\n");
	ft_fill_labels(info.atoken);
//	ft_token_display_all(info.atoken);
//	ft_tests_syntax();
//	printf("test display\n");
	ft_create_champ(&info);
//	ft_create_champ(&info);
	ft_display(&info);
	if (info.error != 1)
		printf("\nWriting output program to %s.cor\n", argv[1]);
	return (0);
}
