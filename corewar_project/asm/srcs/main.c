/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:22:10 by msicot            #+#    #+#             */
/*   Updated: 2018/06/29 14:54:11 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_info(t_asm *info)
{
	//coucou gautier
	
	info->name_f = 0;
	info->comment_f = 0;
	ft_bzero(info->name, PROG_NAME_LENGTH + 1 );
	ft_bzero(info->comment, COMMENT_LENGTH + 1);
	info->line_nb = 0;
	info->error = 0;
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

	init_info(&info);
/*	ft_test_params();
	ft_printf("SAVINEIEN SEGF\n");
	ft_token_add(&info, "%:live"); //remplacer par l'arg de Martin
	ft_token_add(&info, "2"); //remplacer par l'arg de Martin
	ft_token_add(&info, "sti"); //remplacer par l'arg de Martin
	ft_token_add(&info, "r1"); //remplacer par l'arg de Martin
	ft_token_add(&info, "r2"); //remplacer par l'arg de Martin
	ft_token_add(&info, "%1"); //remplacer par l'arg de Martin
	ft_token_display_all(info.atoken);
//	ft_token_display(info.atoken);
//	*/
	ft_printf("SAVINEIEN SEGF 2\n");
	if (argc < 2 || argc > 2 || argv[1] == NULL)
		perror("Error");
	else if ((info.fp = ft_open(argv[1])) == 0)
		return (0);
	else
	{
		printf("ft_gnl\n");
		ft_gnl(&info);
	}
	//char *line = ft_strdup("tird:    sti    r10,%:fin,r3");
//	ft_split_line(line);
	return (0);
}
