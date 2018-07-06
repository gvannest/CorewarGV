/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:38:03 by srossi            #+#    #+#             */
/*   Updated: 2018/07/06 10:39:37 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	ft_pos_increment(t_asm *sasm, t_token *new_token)
{
	if (new_token->opcode > -1)
		sasm->last_opcode = new_token->opcode;
	if (new_token->type == T_DIR
			&& op_tab[sasm->last_opcode - 1].dir_oct_size == 1)
		sasm->pos += 2;
	else if (new_token->type == T_DIR
			&& op_tab[sasm->last_opcode - 1].dir_oct_size == 0)
		sasm->pos += 4;
	else
		sasm->pos++;
}

void			ft_token_add_tail(t_token **token, t_token *new_token)
{
	t_token *p_token;

	p_token = *token;
	if (new_token != NULL)
	{
		if (p_token == NULL)
			*token = new_token;
		else
		{
			while (p_token->next != NULL)
				p_token = p_token->next;
			p_token->next = new_token;
		}
		new_token->next = NULL;
	}
}

void			ft_token_init(t_token *new_token)
{
	new_token->type = -1;
	new_token->s_val = NULL;
	new_token->i_val = -1;
	new_token->opcode = -1;
	new_token->ocp = -1;
	new_token->pos = -1;
	new_token->line = -1;
	new_token->cl = -1;
	new_token->next = NULL;
}

void			ft_token_load(t_asm *sasm, t_token *token, char *arg)
{
	int arg_ln;

	arg_ln = ft_strlen(arg);
	token->type = ft_get_type(arg);
	token->s_val = ft_strdup(arg);
	if (token->type == T_OP)
	{
		token->opcode = ft_get_opcode(arg);
		sasm->last_opcode = token->opcode;
	}
	else if (token->type == T_REG)
		token->i_val = ft_atoi(&token->s_val[1]);
	token->line = sasm->line_nb;
	token->cl = sasm->err_pos;
	token->pos = sasm->pos;
}

void			ft_token_add(t_asm *sasm, char *arg)
{
	t_token *new_token;

	new_token = ft_memalloc(sizeof(t_token));
	ft_token_init(new_token);
	ft_token_load(sasm, new_token, arg);
	ft_token_add_tail(&sasm->atoken, new_token);
	ft_pos_increment(sasm, new_token);
}
