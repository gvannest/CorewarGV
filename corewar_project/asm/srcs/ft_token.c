/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:38:03 by srossi            #+#    #+#             */
/*   Updated: 2018/07/12 11:58:35 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	ft_pos_increment(t_asm *info, t_token *new_token)
{
	if (new_token->opcode > 0)
		info->last_opcode = new_token->opcode;
	if ((new_token->type == T_DIR || new_token->type == T_DIR_LAB)
			&& op_tab[info->last_opcode - 1].dir_oct_size == 1)
		info->pos += 2;
	else if ((new_token->type == T_DIR || new_token->type == T_DIR_LAB)
			&& op_tab[info->last_opcode - 1].dir_oct_size == 0)
		info->pos += 4;
	else if (new_token->type == T_OP
			&& op_tab[info->last_opcode - 1].nb_params > 1)
		info->pos += 2;
	else
		info->pos++;
}

static	int	ft_find_index_arg(char *arg)
{
	int index;

	index = 0;
	while (index < 17)
	{
		if (ft_strequ(arg, op_tab[index].name))
			break ;
		index++;
	}
	return (index);
}
static	void	ft_load_values_info(t_asm *info, char *arg, t_token *token)
{
	int index_tab;

	index_tab = 0;
	if (token->type == T_OP)
	{
			index_tab = ft_find_index_arg(arg);
			printf("INDEX :  %d\n", index_tab);
			if (index_tab < 16)
			{
				info->size = ((op_tab[index_tab].dir_oct_size == 0)? 4 : 2);
				printf("SIZE :  %d\n", op_tab[index_tab].dir_oct_size);
				info->nb_params = op_tab[index_tab].nb_params;
				printf("NB_PARAMS :  %d\n", op_tab[index_tab].nb_params);
			}
	}
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
	new_token->ocp = 0;
	new_token->pos = -1;
	new_token->line = -1;
	new_token->cl = -1;
	new_token->arg_size = 1;
	new_token->nb_params = 0;
	new_token->next = NULL;
}

static	void			ft_token_reload(t_asm *info, t_token *token)
{
	token->pos = info->pos;
	token->nb_params = info->nb_params;
	token->arg_size = info->size;
	token->line = info->line_nb;
	token->cl = info->err_pos;
	token->pos = info->pos;
}

void			ft_token_load(t_asm *info, t_token *token, char *arg)
{
	int arg_ln;

	arg_ln = ft_strlen(arg);
	token->type = ft_get_type(arg);
	token->s_val = ft_strdup(arg);
	if (token->type == T_OP)
	{
		token->opcode = ft_get_opcode(arg);
		info->last_opcode = token->opcode;
		info->operator_f = 1;
	}
	else if (token->type == T_REG)
	{
		token->i_val = ft_atoi(&token->s_val[1]);
		info->nb_param++;
	}
	else if (token->type == T_IND || token->type == T_IND_LAB || token->type == T_DIR_LAB || token->type == T_DIR)
		info->nb_param++;
}

void			ft_token_add(t_asm *info, char *arg)
{
	t_token *new_token;

	new_token = ft_memalloc(sizeof(t_token));
	ft_token_init(new_token);
	ft_token_load(info, new_token, arg);
	ft_load_values_info(info, arg, new_token);
	ft_token_reload(info, new_token);
	ft_token_add_tail(&info->atoken, new_token);
	ft_pos_increment(info, new_token);
}
