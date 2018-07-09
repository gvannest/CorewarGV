/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:01:10 by srossi            #+#    #+#             */
/*   Updated: 2018/07/06 14:55:33 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void ft_set_magic_number(char *champ)
{
	champ[0] = 0x00;
	champ[1] = 0xEA;
	champ[2] = 0x83;
	champ[3] = 0xF3;
}

/*
static	void ft_add_instr(char *champ, t_token *atoken)
{
	t_token *p_token;
	
	p_token = atoken;
	while (p_token)
	{
		champ[0] = 0x00;
		p_token = p_token->next;
	}
}

static void ft_add_prog_name(char *champ, char *prog_name)
{
	(void)prog_name;
	champ[0] = 0x00;
}

static void ft_add_null_oct(char *champ)
{
	champ[0] = 0x00;
	champ[1] = 0x00;
	champ[2] = 0x00;
	champ[3] = 0x00;
}

static void ft_add_nb_instr(char *champ, int nb_instr)
{
	int i;
	
	i = 0;
	while (i < nb_instr)
	{
		i++;
	}
	champ[0] = 0x00;
	
}

static void ft_add_comment(char *champ, char *comment)
{
	(void)comment;
	champ[0] = 0x00;
}
*/

void	ft_create_champ(t_asm *info)
{
	ft_set_magic_number(info->tab);
//	printf("test2 : %.2hhX\n", info->tab[1]);
//	ft_add_prog_name(info->tab, info->name);
//	ft_add_null_oct(info->tab);
//	ft_add_nb_instr(info->tab, info->nb_instr);
//	ft_add_comment(info->tab, info->comment);
//	ft_add_null_oct(info->tab);
//	ft_add_instr(info->tab, info->atoken);
}

