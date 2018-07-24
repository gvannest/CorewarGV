/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:01:10 by srossi            #+#    #+#             */
/*   Updated: 2018/07/19 14:20:58 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	ft_load_ocp(t_token *token_op)
{
	t_token	*p_token;
	int		params_nb;
	int		index;

	p_token = token_op->next;
	params_nb = token_op->nb_params;
	index = 6;
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
}

static	void	ft_load_int(int nb, char *champ)
{
	unsigned char octets[4];
	int index;

	index = 0;
	octets[0] = nb >> 0;
	octets[1] = nb >> 8;
	octets[2] = nb >> 16;
	octets[3] = nb >> 24;
	ft_swap_bytes_int(octets);
	while (index < 4)
	{
		champ[index] = octets[index];
		index++;
	}
	//	printf("%.2X%.2X %.2X%.2X\n", octets[0], octets[1], octets[2], octets[3]);
}

static	void	ft_load_short(short nb, char *champ)
{
	unsigned char octets[2];
	unsigned char tmp;
	int index;

	index = 0;
	octets[0] = nb >> 0;
	octets[1] = nb >> 8;
	tmp = octets[0];
	ft_swap_bytes_short(octets);
	champ[0] = octets[0];
	champ[1] = octets[1];
//	printf("%.2X%.2X ", octets[0], octets[1]);
}

void	ft_create_champ(t_asm *info)
{
	t_token	*p_token;
	int		index;

	index = 0;
	p_token = info->atoken;
	while (p_token)
	{
		if (index + p_token->arg_size > CHAMP_MAX_SIZE)
		{
			printf("Your champion is too big, go WW\n");
			exit(EXIT_FAILURE);
		}
		if (p_token->type == T_OP)
		{
			ft_load_ocp(p_token);
			info->tab[index++] = p_token->opcode;
			if (p_token->nb_params > 1)
				info->tab[index++] = p_token->ocp;
		}
		else if (p_token->type == T_REG)
			info->tab[index++] = p_token->i_val;
		else if (p_token->type == T_DIR || p_token->type == T_DIR_LAB)
		{
			if (p_token->arg_size == 2)
				ft_load_short((short)p_token->i_val, &info->tab[index]);
			else if (p_token->arg_size == 4)
				ft_load_int((int)p_token->i_val, &info->tab[index]);
			index += p_token->arg_size;
		}
		else if (p_token->type == T_IND || p_token->type == T_IND_LAB)
			info->tab[index++] = p_token->i_val;
		p_token = p_token->next;
	}
}
