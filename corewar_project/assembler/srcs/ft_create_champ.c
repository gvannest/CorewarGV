/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:01:10 by srossi            #+#    #+#             */
/*   Updated: 2018/08/02 11:19:04 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_create_champ(t_asm *info)
{
	t_token	*p_token;
	int		index;

	index = 0;
	p_token = info->atoken;
	if (info->comment_f == 0 || info->name_f == 0
			|| (info->nb_instr == 0 && !p_token))
		ft_error_incomplete(info, 1);
	if (info->nb_params_left > 0)
	{
		if (info->comma_f == 1)
			ft_error_incomplete(info, 2);
		else if (info->comma_f <= 0)
			ft_error_param(info, p_token, 1);
	}
	while (p_token)
	{
		if (index + p_token->arg_size > CHAMP_MAX_SIZE)
			ft_error_param(info, p_token, 5);
		if (p_token->type == T_OP)
		{
			ft_load_ocp(p_token);
			p_token->arg_size = 1;
			info->tab[index++] = p_token->opcode;
			if (p_token->nb_params > 1)
			{
				info->tab[index++] = p_token->ocp;
				p_token->arg_size++;
			}
			info->last_cor_index = index;
		}
		else if (p_token->type == T_REG)
		{
			p_token->arg_size = 1;
			info->tab[index++] = p_token->i_val;
		}
		else if (p_token->type == T_DIR || p_token->type == T_DIR_LAB)
		{
			if (p_token->arg_size == 2)
				ft_load_short((short)p_token->i_val, &info->tab[index]);
			else if (p_token->arg_size == 4)
				ft_load_int((int)p_token->i_val, &info->tab[index]);
			index += p_token->arg_size;
		}
		else if (p_token->type == T_IND || p_token->type == T_IND_LAB)//fusionner avec if cidessus DIR ?
		{
			ft_load_short((short)p_token->i_val, &info->tab[index]);
			index += p_token->arg_size;
		}
		p_token->last_cor_index = info->last_cor_index;
		info->nb_instr = index;
		p_token = p_token->next;
	}
}
