/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:22:10 by msicot            #+#    #+#             */
/*   Updated: 2018/08/03 14:00:54 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	t_asm	info;
	char	*champ_path;

	ft_bzero(&info, sizeof(t_asm));
	ft_init_info(&info);
	if (!ft_is_valid_syntax(&info))
		ft_error_syntax(&info);
	ft_check_argv(&info, argv, argc);
	ft_gnl(&info);
	champ_path = ft_strjoin(info.path, info.true_name);
	info.fd_cor = ft_open_champ(champ_path);
	ft_strdel(&champ_path);
	ft_fill_labels(info.atoken);
	ft_create_champ(&info);
	ft_write(&info);
	if (info.f_option_d)
		ft_option_display(&info);
	if (info.error != 1)
		ft_printf("Writing output program to %s%s.cor\n",
				info.path, info.true_name);
	close(info.fd_cor);
	ft_free(&info);
	return (0);
}
