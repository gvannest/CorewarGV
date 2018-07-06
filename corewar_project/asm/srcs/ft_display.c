/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:10:36 by srossi            #+#    #+#             */
/*   Updated: 2018/07/06 14:56:02 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_token_display(t_token *token, int token_nb)
{
	ft_printf("TOKEN %d:\n", token_nb);
	if (token != NULL)
	{
		ft_printf("    Type : %d\n", token->type);
		if (token->s_val != NULL)
			ft_printf("    S_val : %s\n", token->s_val);
		else
			ft_printf("    S_val : NULL\n");
		ft_printf("    I_val : %d\n", token->i_val);
		ft_printf("    opcode : %d\n", token->opcode);
		ft_printf("    ocp : %d\n", token->ocp);
		ft_printf("    Pos : %d\n", token->pos);
		ft_printf("    Line : %d\n", token->line);
		ft_printf("    Cl : %d\n", token->cl);
	}
	else
		ft_printf("ERROR. NULL TOKEN\n");
}

void	ft_token_display_all(t_token *atoken)
{
	t_token *p_token;
	int		token_nb;

	token_nb = 0;
	p_token = atoken;
	while (p_token)
	{
		ft_token_display(p_token, token_nb);
		token_nb++;
		p_token = p_token->next;
	}
}

static	void	ft_champ_display(char champ[CHAMP_MAX_SIZE])
{
	int index;

	index = 0;
	while (index < CHAMP_MAX_SIZE)
	{
		if (index % 16 == 0 && index != 0)
			printf("\n");
		if (index % 2 == 0)
			printf(" ");
		printf("%.2x", champ[index]);
		index++;
	}
}

void	ft_name_display(char name[PROG_NAME_LENGTH + 1])
{
	int index;

	index = 0;
	while (index < PROG_NAME_LENGTH)
	{
		if (index % 16 == 0 && index != 0)
			printf("\n");
		if (index % 2 == 0)
			printf(" ");
		printf("%.2x", name[index]);
		index++;
	}
}

void	ft_comment_display(char comment[COMMENT_LENGTH + 1])
{
	int index;

	index = 0;
	while (index < COMMENT_LENGTH)
	{
		if (index % 16 == 0 && index != 0)
			printf("\n");
		if (index % 2 == 0)
			printf(" ");
		printf("%.2x", comment[index]);
		index++;
	}
}

/*void	ft_comment_display()
{
	printf("00 EA 83 F3");
}*/

void	ft_display(t_asm *info)
{
//	printf("magic nb   n ----\n\n");
//	ft_magic_nb(info->name);
//	printf("name section ----\n\n");
//	ft_name_display(info->name);
	printf("\ncomment section ----\n\n");
	ft_comment_display(info->comment);
	printf("\nchamp section ----\n\n");
	ft_champ_display(info->tab);
}
