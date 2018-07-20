/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:26:06 by srossi            #+#    #+#             */
/*   Updated: 2018/07/19 13:49:28 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_check_token(t_asm *info, t_token *token)
{
	char	type;

	type = token->type;
	if (type == T_DIR_LAB)
		type = T_DIR;
	else if (type == T_IND_LAB)
		type = T_IND;
	if (token->type == T_DIR_LAB || token->type == T_IND_LAB
			|| token->type == T_DIR || token->type == T_IND)
	{
		/*if (info->nb_params_left < 0)
		{
			printf("ERROR TOO MANY ARGUMENTS\n");
		//	printf("argument : %s\n", token->s_val);
		}
		else if (op_tab[info->last_opcode - 1].nb_params < info->cur_param)
		{
			printf("ERROR: cur param too big for operation\n");
		}*/
		if ((op_tab[info->last_opcode - 1].param_type[info->cur_param - 1]
					& type) == 0)
			ft_error_param(info, token, 3);
	}
}
