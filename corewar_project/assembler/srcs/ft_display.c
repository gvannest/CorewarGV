/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:10:36 by srossi            #+#    #+#             */
/*   Updated: 2018/07/13 14:50:32 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_token_display(t_token *token, int token_nb)
{
	printf("TOKEN %d:\n", token_nb);
	if (token != NULL)
	{
	//	printf("    Type : %d\n", token->type);
		if (token->s_val != NULL)
			printf("    S_val : %10s   ", token->s_val);
		else
			printf("    S_val : NULL   ");
		//	printf("    I_val : %d\n", token->i_val);
//		printf("    opcode : %d\n", token->opcode);
//		printf("    ocp : %d\n", token->ocp);
		//printf("    Pos : %d\n", token->pos);
		printf("    Pos : %2d   ", token->pos);
		printf("    Arg_size : %2d\n", token->arg_size);
//		printf("    Line : %d\n", token->line);
//		printf("    Cl : %d\n", token->cl);
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
