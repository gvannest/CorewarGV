/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:05 by srossi            #+#    #+#             */
/*   Updated: 2018/07/12 17:02:20 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_clean_label(char *label)
{
	char	*clean_label;
	int		label_ln;

	clean_label = NULL;
	label_ln = ft_strlen(label);
	if (label[0] == LABEL_CHAR)
		clean_label = ft_strsub(label, 1, label_ln - 1);
	else if (label[0] == DIRECT_CHAR && label[1] == LABEL_CHAR)
		clean_label = ft_strsub(label, 2, label_ln - 2);
	else if (label[label_ln - 1] == LABEL_CHAR)
		clean_label = ft_strsub(label, 0, label_ln - 1);
	return (clean_label);
}

t_token		*ft_find_label(t_token *atoken, char *label)
{
	t_token	*p_token;
	char	*clean_label;

	clean_label = ft_clean_label(label);
	p_token = atoken;
	while (p_token)
	{
		if (p_token->type == T_LAB &&
				ft_strequ(ft_clean_label(p_token->s_val), clean_label))
		{
			ft_printf("trouve !\n");
			break ;
		}
		p_token = p_token->next;
	}
	if (p_token == NULL)
		ft_printf("pas trouve !\n");
	ft_strdel(&clean_label);
	return (p_token);
}

void		ft_fill_label(t_token *token_src, t_token *token_dst)
{
	printf("dest pos : %d et src pos : %d\n", token_dst->pos, token_src->pos);
	if (token_dst->pos > token_src->pos)
		token_src->i_val = token_dst->pos - token_src->pos;
	else if (token_dst->pos < token_src->pos)
		token_src->i_val = token_dst->pos - token_src->pos;
}

static	void		ft_fill_dir_label(t_token *token_src, t_token *token_dst)
{
	printf("dest pos : %d et src pos : %d\n", token_dst->pos, token_src->pos);
	token_src->i_val = token_dst->pos;
}

void		ft_fill_labels(t_token *atoken)
{
	t_token *p_token_src;
	t_token *p_token_dst;

	p_token_src = atoken;
	p_token_dst = atoken;
	while (p_token_src)
	{
		p_token_dst = atoken;
		if (p_token_src->type == T_IND_LAB)
		{
			p_token_dst = ft_find_label(p_token_dst, p_token_src->s_val);
			ft_fill_label(p_token_src, p_token_dst);
		}
		else if (p_token_src->type == T_DIR_LAB)
		{
			p_token_dst = ft_find_label(p_token_dst, p_token_src->s_val);
			ft_fill_dir_label(p_token_src, p_token_dst);
		}
		p_token_src = p_token_src->next;
	}
}
