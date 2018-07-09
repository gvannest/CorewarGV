/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:01:10 by srossi            #+#    #+#             */
/*   Updated: 2018/07/09 18:51:31 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void ft_load_ocp(t_token *token_op)
{
	t_token *p_token;
	int		params_nb;
	int		index;

	p_token = token_op;
	params_nb = 3; // A remplacer dans struct token par nb params de l'operation
	index = params_nb * 2;
	while (index < params_nb)
	{
		if (p_token->type == T_DIR_LAB)
			token_op->ocp  = p_token->ocp | (p_token->ocp << index & 2);
		else if (p_token->type == T_IND_LAB || p_token->type == T_IND)
			token_op->ocp  = p_token->ocp | (p_token->ocp << index & 3);
		else
			token_op->ocp  = p_token->ocp | (p_token->ocp << index & p_token->type);
		index -= 2;
		p_token = p_token->next;
	}
	printf("token ocp : %c\n\n", token_op->ocp);
}

void	ft_create_champ(t_asm *info)
{
	t_token	*p_token;
	int		index;

	index = 0;
	p_token = info->atoken;
	while (p_token)
	{
		printf("%hhX\n", p_token->opcode);
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
		p_token = p_token->next;
	}
}

