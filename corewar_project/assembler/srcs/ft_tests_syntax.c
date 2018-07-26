/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:37:27 by srossi            #+#    #+#             */
/*   Updated: 2018/07/06 10:37:41 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	init_info(t_asm *info)
{
	info->last_opcode = -1;
	info->err_pos = -1;
}

void			ft_tests_syntax(void)
{
	t_asm info;

	ft_bzero(&info, sizeof(t_asm));
	init_info(&info);
	ft_token_add(&info, "label:");
	ft_token_add(&info, "sti");
	ft_token_add(&info, "r1");
	ft_token_add(&info, "r2");
	ft_token_add(&info, "r1");
	ft_token_add(&info, "label:");
	ft_token_add(&info, "sti");
	ft_token_add(&info, "r1");
	ft_token_add(&info, "r2");
	ft_token_add(&info, "r2");
	ft_token_display_all(info.atoken);
	printf("Valid syntax ? : %d\n", ft_is_valid_syntax(&info));
}
