/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:22:10 by msicot            #+#    #+#             */
/*   Updated: 2018/07/19 15:14:23 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_info(t_asm *info)
{
	info->last_opcode = -1;
	info->err_pos = -1;
	info->nb_params = 0;
	info->size = 1;
	info->last_op_line = -1;
}

int	ft_open_champ(char *path)
{
	int		fp;
	char	*champ_file;

	champ_file = ft_strjoin(path, ".cor");
	fp = 0;
	fp = open(champ_file, O_WRONLY | O_CREAT | O_TRUNC, 00700);
	ft_strdel(&champ_file);
	return (fp);
}
int	main(int argc, char **argv)
{
	(void) argc;
	t_asm	info;
	(void) argv;
	char	*champ_path;

	ft_bzero(&info, sizeof(t_asm));
	init_info(&info);
//	printf("Valid syntax ? : %d\n", ft_is_valid_syntax(&info));
	if (!ft_is_valid_syntax(&info))
	{
		printf("error syntax\n");
		exit(EXIT_FAILURE);
	}
	ft_check_argv(&info, argv, argc);
	ft_gnl(&info);
	champ_path = ft_strjoin(info.path, info.true_name);
	info.fd_cor = ft_open_champ(champ_path);
	ft_strdel(&champ_path);
	ft_fill_labels(info.atoken);
//	ft_putstr("echo 1\n");
	ft_create_champ(&info);
//	ft_putstr("echo 2\n");
	ft_write(&info);
	if (info.f_option_d)
	{
		ft_display(&info);
		exit(EXIT_SUCCESS);
	}
	ft_token_list_free(info.atoken);
	if (info.error != 1)
		printf("Writing output program to %s%s.cor\n", info.path, info.true_name);
	close (info.fd_cor);
	return (0);
}
