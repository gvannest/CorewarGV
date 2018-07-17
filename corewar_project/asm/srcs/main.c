/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:22:10 by msicot            #+#    #+#             */
/*   Updated: 2018/07/17 17:05:37 by srossi           ###   ########.fr       */
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

int	ft_open_champ(char *path)
{
	int	fp;

	fp = 0;
	fp = open(path, O_WRONLY | O_CREAT | O_TRUNC, 00700);
	return (fp);
}
int	main(int argc, char **argv)
{
	(void) argc;
	t_asm	info;
	(void) argv;
	char	*champ_file;

	ft_bzero(&info, sizeof(t_asm));
	init_info(&info);
//	ft_token_display_all(info.atoken);
//	printf("Valid syntax ? : %d\n", ft_is_valid_syntax(&info));
//	if (!ft_is_valid_syntax(&info))
//		error_instr(info, 
//	ft_fill_labels(info.atoken);
//	ft_test_params();
//	ft_test_label();
	ft_check_argv(&info, argv, argc);
	ft_gnl(&info);
	champ_file = ft_strjoin(info.name, ".cor");
	info.fd_cor = ft_open_champ(champ_file);
	ft_strdel(&champ_file);
	ft_fill_labels(info.atoken);
//	ft_token_display_all(info.atoken);
//	ft_tests_syntax();
//	printf("test display\n");
	ft_create_champ(&info);
//	ft_create_champ(&info);
/*
	if (info,f_option_display)
		ft_display(&info);
		flag d'option, si active il faut afficher le .cor style xxd
*/
	ft_write(&info);
	ft_token_list_free(info.atoken);
	if (info.error != 1)
		ft_printf("Writing output program to %s.cor\n", argv[1]);
	close (info.fd_cor);
	return (0);
}
