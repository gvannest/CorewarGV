/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:36:28 by srossi            #+#    #+#             */
/*   Updated: 2018/07/06 10:37:19 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	init_info(t_asm *info)
{
	info->name_f = 0;
	info->comment_f = 0;
	ft_bzero(info->name, PROG_NAME_LENGTH + 1);
	ft_bzero(info->comment, COMMENT_LENGTH + 1);
	info->line_nb = 0;
	info->error = 0;
	info->err_pos = -1;
}

static	void	ft_test_clean_label(void)
{
	printf("%s\n", ft_clean_label("label1"));
	printf("%s\n", ft_clean_label("%:label1"));
	printf("%s\n", ft_clean_label(":label1"));
	printf("%s\n", ft_clean_label("label1:"));
	printf("%s\n", ft_clean_label("%label1"));
	printf("%s\n", ft_clean_label("label1%"));
}

void			ft_test_label(void)
{
	t_asm info2;

	ft_bzero(&info2, sizeof(t_asm));
	init_info(&info2);
	ft_token_add(&info2, "2");
	ft_token_add(&info2, "%1");
	ft_token_add(&info2, "%:live");
	ft_token_display_all(info2.atoken);
	ft_fill_labels(info2.atoken);
	ft_token_display_all(info2.atoken);
	ft_test_clean_label();
}
