/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:01:10 by srossi            #+#    #+#             */
/*   Updated: 2018/07/12 11:40:12 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void ft_load_ocp(t_token *token_op)
{
	t_token *p_token;
	int		params_nb;
	int		index;

	p_token = token_op->next;
	params_nb = token_op->nb_params;
	printf("nb params op : %d\n", params_nb);
	index = 6;
//	ft_printf("token ocp : %b\n\n", token_op->ocp);
	while (index >= 6 / params_nb)
	{
		if (p_token->type == T_DIR_LAB)
			token_op->ocp  = token_op->ocp | (2 << index);
		else if (p_token->type == T_IND_LAB || p_token->type == T_IND)
			token_op->ocp  = token_op->ocp | (3 << index);
		else
			token_op->ocp  = token_op->ocp | (p_token->type << index);
		index -= 2;
		p_token = p_token->next;
	}
	ft_printf("token fin bin : 0%b\n", token_op->ocp);
	ft_printf("token fin hex : %x\n", token_op->ocp);
}

void	ft_create_champ(t_asm *info)
{
	t_token	*p_token;
	int		index;

	index = 0;
	p_token = info->atoken;
	while (p_token)
	{
		if (p_token->type == T_OP)
		{
			printf("\nname OP : %s\n", p_token->s_val);
			ft_load_ocp(p_token);
			info->tab[index++] = p_token->opcode;
			if (p_token->nb_params > 1)
				info->tab[index++] = p_token->ocp;

		}
		else if (p_token->type == T_REG)
		{
			info->tab[index++] = p_token->i_val;
		}
		else if (p_token->type == T_DIR || p_token->type == T_DIR_LAB)
		{
			printf("alert! i_val : %d\n", p_token->i_val);
			if (p_token->arg_size == 2)
			{
				ft_write_short((short)p_token->i_val); // remplacer par load short
				index += 2;
			}
			if (p_token->arg_size == 4)
			{
				ft_write_int(p_token->i_val); //remplacer par load int
				index += 4;
			}
		}
		else if (p_token->type == T_IND || p_token->type == T_IND_LAB)
		{
			info->tab[index++] = p_token->i_val;
		}
		p_token = p_token->next;
	}
}

