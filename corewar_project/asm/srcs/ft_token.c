/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:38:03 by srossi            #+#    #+#             */
/*   Updated: 2018/06/27 18:53:52 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_token_add_tail(t_token *token, t_token *new_token)
{
	t_token *p_token;

	p_token = token;
	if (new_token != NULL)
	{
		if (token == NULL)
			token = new_token;
		else
		{
			while (p_token->next != NULL)
				p_token = p_token->next;
			p_token->next = new_token;
		}
		new_token->next = NULL;
	}
}

void	ft_token_init(t_token *new_token)
{
	new_token->type = NULL;
	new_token->s_val = NULL;
	new_token->i_val = -1;
	new_token->pos = -1;
	new_token->line = -1;
	new_token->cl = -1;
	new_token->next = NULL;
}

void	ft_token_load(t_asm *sasm, char *arg, t_token *token)
{
	int pos;
	int arg_ln;
	int arg_type;

	arg_type = ft_get_type(arg);
	arg_ln = ft_strlen(arg);
	if (ft_is_label(arg))
		token->s_val = ft_strndup(arg, arg_ln - 1);
	else
		token->s_val = ft_strdup(arg);
	token->i_val = ft_get_ival(arg); // recuperer l'opcode si operation dans tableau sinon valeur registre/dir/label/indirect
	token->line = sasm->line_nb;
	token->cl = sasm->err_pos;
	pos = sasm->err_pos;
	sasm->err_pos += arg_ln;
}

int ft_get_ival(char *arg)
{
	int ival;

	ival = 0;
	if (ft_is_label(arg))
		ival = T_LAB;
	else if (ft_is_reg(arg))
		ival = T_REG;
	else if (ft_is_dir(arg))
		ival = T_DIR;
	else if (ft_is_ind(arg))
		ival = T_IND;
	else if (ft_is_op(arg))
		ival = T_OP;
	return (ival);
}

int	ft_get_opcode(char *arg)
{
	int index;

	index = 0;
	while (index < NB_INSTR)
	{
		if (ft_strcmp(op_tab[index].name, arg) == 0)
			return (op_tab[index].opcode);
		index++;
	}
	return (-1);

}

void	ft_token_free(t_token *token)
{
	ft_strdel(&token->type);
	ft_strdel(&token->s_val);
	free(token->next);
	free(token);
}

void	ft_token_list_free(t_token *a_token)
{
	t_token *p_token;

	p_token = a_token;
	if (p_token != NULL)
	{
		p_token = a_token->next;
		while (a_token != NULL)
		{
			ft_token_free(a_token);
			a_token = p_token;
			p_token = a_token->next;
		}
		free(p_token);
		free(a_token);
	}
}

int	ft_get_type(char *arg)
{

	if (ft_is_label(arg))
	{
		ft_printf("%s \n", "LABEL");
		return (8);
	}
	else if (ft_is_reg(arg))
	{
		ft_printf("%s \n", "REG");
		return (1);
	}
	else if (ft_is_dir(arg))
	{
		ft_printf("%s \n", "DIR");
		return (2);
	}
	else if (ft_is_ind(arg))
	{
		ft_printf("%s \n", "IND");
		return (4);
	}
	return (0);

}
