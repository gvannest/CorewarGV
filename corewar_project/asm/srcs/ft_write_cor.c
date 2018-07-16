/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:21:45 by srossi            #+#    #+#             */
/*   Updated: 2018/07/13 15:43:53 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	ft_write_champ(t_asm *info)
{
	int index;
	t_token *p_token;
	int	champ_ln;

	index = 0;
	p_token = info->atoken;
	while (p_token->next)
		p_token = p_token->next;
	champ_ln = p_token->pos + p_token->arg_size;
	while (index < champ_ln)
	{
		if (index % 16 == 0)
			printf("\n");
		if (index % 2 == 0)
			printf(" ");
		printf("%.2hhx", info->tab[index]);
		index++;
	}
	printf(" ");
}

void	ft_write_name(char *name)
{
	int index;

	index = 0;
	while (index < PROG_NAME_LENGTH)
	{
		if ((index + 4) % 16 == 0)
			printf("\n");
		if (index % 2 == 0 && index != 0)
			printf(" ");
		printf("%.2x", name[index]);
		index++;
	}
	printf(" ");
}

void	ft_write_comment(char *comment)
{
	int index;

	index = 0;
	while (index < COMMENT_LENGTH)
	{
		if ((index + 12) % 16 == 0 && index != 0)
			printf("\n");
		if (index % 2 == 0 && index != 0)
			printf(" ");
		printf("%.2x", comment[index]);
		index++;
	}
	printf(" ");
}

void	ft_write_int(int nb)
{
	unsigned char octets[4];
	int index;

	index = 0;
	octets[0] = nb >> 0;
	octets[1] = nb >> 8;
	octets[2] = nb >> 16;
	octets[3] = nb >> 24;
	ft_swap_bytes_int(octets);
	printf("%.2x%.2x %.2x%.2x ", octets[0], octets[1], octets[2], octets[3]);
}

void	ft_write_short(short nb)
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
	printf("%.2x%.2x ", octets[0], octets[1]);
}

void	ft_display(t_asm *info)
{
	int magic;

	magic = 0x00EA83F3;
	ft_write_int(magic);
	ft_write_name(info->name);
	ft_write_int(0);
	ft_write_int(info->pos);
	ft_write_comment(info->comment);
	ft_write_int(0);
	ft_create_champ(info);
	ft_write_champ(info);
}
