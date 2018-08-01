/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:47:46 by srossi            #+#    #+#             */
/*   Updated: 2018/08/01 19:29:00 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_is_valid_syntax(t_asm *info)
{
	t_token *p_token;

	info->nb_params_left = 0;
	p_token = info->atoken;
	while (p_token)
	{
		if (p_token->type == T_OP)
		{
			if (info->nb_params_left != 0)
				return (0);
			info->nb_params_left = g_op_tab[p_token->opcode - 1].nb_params;
			info->last_opcode = p_token->opcode;
			info->cur_param = 0;
		}
		else if (p_token->type != T_LAB)
		{
			if (info->nb_params_left <= 0)
				return (0);
			info->nb_params_left--;
			info->cur_param++;
		}
		else if (p_token->type == T_LAB && info->nb_params_left > 0)
			return (0);
		p_token = p_token->next;
	}
	if (info->nb_params_left > 0)
		return (0);
	return (1);
}
