/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:47:46 by srossi            #+#    #+#             */
/*   Updated: 2018/08/02 11:17:33 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	ft_syntax_op(t_asm *info, t_token *p_token)
{
	info->nb_params_left = g_op_tab[p_token->opcode - 1].nb_params;
	info->last_opcode = p_token->opcode;
	info->cur_param = 0;
}

static	void	ft_syntax_param_increase(t_asm *info)
{
	info->nb_params_left--;
	info->cur_param++;
}

int				ft_is_valid_syntax(t_asm *info)
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
			ft_syntax_op(info, p_token);
		}
		else if (p_token->type != T_LAB)
		{
			if (info->nb_params_left <= 0)
				return (0);
			ft_syntax_param_increase(info);
		}
		else if (p_token->type == T_LAB && info->nb_params_left > 0)
			return (0);
		p_token = p_token->next;
	}
	if (info->nb_params_left > 0)
		return (0);
	return (1);
}
