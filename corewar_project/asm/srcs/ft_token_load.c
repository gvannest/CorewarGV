/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:27:48 by srossi            #+#    #+#             */
/*   Updated: 2018/07/19 13:47:20 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_load_values_info(t_asm *info, char *arg, t_token *token)
{
	int index_tab;

	index_tab = 0;
	if (token->type == T_OP)
	{
		index_tab = ft_find_index_arg(arg);
		info->nb_params_left = op_tab[index_tab].nb_params;
		if (index_tab < 16)
		{
			info->size = ((op_tab[index_tab].dir_oct_size == 0) ? 4 : 2);
			info->nb_params = op_tab[index_tab].nb_params;
		}
	}
}

void			ft_token_reload(t_asm *info, t_token *token)
{
	token->pos = info->pos;
	token->nb_params = info->nb_params;
	token->arg_size = info->size;
	token->line = info->line_nb;
	token->cl = info->start;
	token->pos = info->pos;
	token->last_op_pos = info->last_op_pos;
}

static	void	ft_load_op(t_asm *info, t_token *token, char *arg)
{
	token->opcode = ft_get_opcode(arg);
	info->last_opcode = token->opcode;
	info->last_op_pos = info->pos;
	info->cur_param = 0;
	info->operator_f = 1;
}

void			ft_token_load(t_asm *info, t_token *token, char *arg)
{
	int arg_ln;

	arg_ln = ft_strlen(arg);
	token->type = ft_get_type(arg);
	token->s_val = ft_strdup(arg);
	if (token->type == T_OP || token->type == T_LAB)
	{
		if (info->nb_params_left > 0)
			ft_error_param(info, token, 1);
		if (token->type == T_OP)
			ft_load_op(info, token, arg);
	}
	else if (token->type == T_IND || token->type == T_IND_LAB
			|| token->type == T_DIR_LAB || token->type == T_DIR
			|| token->type == T_REG)
	{
		if (info->nb_params_left <= 0)
			ft_error_param(info, token, 2);
		if (token->type == T_DIR || token->type == T_REG)
			token->i_val = ft_atoi(&token->s_val[1]);
		info->nb_param++;
		--info->comma_f; // Ajout MAS
		info->cur_param++;
		info->nb_params_left--;
	}
}
