/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:01:10 by srossi            #+#    #+#             */
/*   Updated: 2018/07/10 16:02:11 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void ft_load_ocp(t_token *token_op)
{
	t_token *p_token;
	int		params_nb;
	int		index;

	p_token = token_op->next;
	token_op->ocp = 0;
	params_nb = 3; // A remplacer dans struct token par nb params de l'operation
	index = params_nb * 2;
//	ft_printf("token ocp : %b\n\n", token_op->ocp);
	while (index > 0)
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
	ft_printf("token fin : 0%b\n\n", token_op->ocp);
	ft_printf("token fin : %x\n\n", token_op->ocp);
}

void	ft_create_champ(t_asm *info)
{
	t_token	*p_token;
	int		index;

	index = 0;
	p_token = info->atoken;
	while (p_token)
	{
		printf("p_token->opcode : %hhX\n", p_token->opcode);
		if (p_token->type == T_OP)
		{
			info->tab[index++] = p_token->opcode;
			ft_load_ocp(p_token);
		}
		else if (p_token->type == T_REG)
		{
			info->tab[index] = p_token->i_val;
			index++;
		}
		else if (p_token->type == T_IND)
		{
			info->tab[index] = p_token->i_val;
			index++;
		}
		else if (p_token->type == T_DIR)
		{
			info->tab[index] = p_token->i_val;
			index++;
		}
		else if (p_token->type == T_DIR_LAB || p_token->type == T_IND_LAB)
		{
			info->tab[index] = p_token->i_val;
			index++;
		}
		p_token = p_token->next;
	}
}

