/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:10:36 by srossi            #+#    #+#             */
/*   Updated: 2018/07/09 15:23:37 by srossi           ###   ########.fr       */
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
