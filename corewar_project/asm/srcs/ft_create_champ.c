/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:01:10 by srossi            #+#    #+#             */
/*   Updated: 2018/07/13 14:50:11 by srossi           ###   ########.fr       */
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
//	printf("nb params op : %d\n", params_nb);
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
//	ft_printf("token fin bin : 0%b\n", token_op->ocp);
//	ft_printf("token fin hex : %x\n", token_op->ocp);
}


static void swap_bytes(unsigned char *t) // attentioin fonction dupliquee pour tests
{
	unsigned char tmp;

	tmp = t[0];
	t[0] = t[3];
	t[3] = tmp;

	tmp = t[1];
	t[1] = t[2];
	t[2] = tmp;
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
	swap_bytes(octets);
	while (index < 4)
	{
		champ[index] = octets[index];
		index++;
	}
//	printf("%.2X%.2X %.2X%.2X ", octets[0], octets[1], octets[2], octets[3]);
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
	octets[0] = octets[1];
	octets[1] = tmp;
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
		if (p_token->type == T_OP)
		{
		//	printf("\nname OP : %s\n", p_token->s_val);
			ft_load_ocp(p_token);
			info->tab[index++] = p_token->opcode;
			if (p_token->nb_params > 1)
				info->tab[index++] = p_token->ocp;

		}
		else if (p_token->type == T_REG)
		{
		//	printf("\nalert! s_val : %s | i_val : %d\n", p_token->s_val, p_token->i_val);
			info->tab[index++] = p_token->i_val;
		}
		else if (p_token->type == T_DIR || p_token->type == T_DIR_LAB)
		{
		//	printf("\nalert! s_val : %s | i_val : %d\n", p_token->s_val, p_token->i_val);
			if (p_token->arg_size == 2)
			{
				ft_load_short((short)p_token->i_val, &info->tab[index]); // remplacer par load short
				index += 2;
			}
			if (p_token->arg_size == 4)
			{
				ft_load_int(p_token->i_val, &info->tab[index]); // remplacer par load short
				//ft_write_int(p_token->i_val); //remplacer par load int
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

