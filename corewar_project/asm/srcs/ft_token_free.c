/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:20:10 by srossi            #+#    #+#             */
/*   Updated: 2018/07/06 10:20:19 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_token_free(t_token *token)
{
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
