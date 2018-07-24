/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:21:45 by srossi            #+#    #+#             */
/*   Updated: 2018/07/19 15:15:35 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	ft_write_champ(t_asm *info)
{
	t_token	*p_token;
	int		index;
	int		champ_ln;

	index = 0;
	p_token = info->atoken;
	while (p_token->next)
		p_token = p_token->next;
	champ_ln = p_token->pos + p_token->arg_size;
	while (index < champ_ln)
	{
		dprintf(info->fd_cor, "%c", info->tab[index]);
		index++;
	}
}

static	void	ft_write_name(char *name, int fd_cor)
{
	int	index;

	index = 0;
	while (index < PROG_NAME_LENGTH)
	{
		dprintf(fd_cor, "%c", name[index]);
		index++;
	}
}

static	void	ft_write_comment(char *comment, int fd_cor)
{
	int	index;

	index = 0;
	while (index < COMMENT_LENGTH)
	{
		dprintf(fd_cor, "%c", comment[index]);
		index++;
	}
}

static	void	ft_write_int(int nb, int fd_cor)
{
	unsigned char	octets[4];
	int				index;

	index = 0;
	octets[0] = nb >> 0;
	octets[1] = nb >> 8;
	octets[2] = nb >> 16;
	octets[3] = nb >> 24;
	ft_swap_bytes_int(octets);
	dprintf(fd_cor, "%c%c%c%c", octets[0], octets[1], octets[2], octets[3]);
}

/*static	void	ft_write_short(short nb, int fd_cor)
{
	unsigned char	octets[2];
	unsigned char	tmp;
	int				index;

	index = 0;
	octets[0] = nb >> 0;
	octets[1] = nb >> 8;
	tmp = octets[0];
	octets[0] = octets[1];
	octets[1] = tmp;
	dprintf(fd_cor, "%c%c ", octets[0], octets[1]);
}*/

void			ft_write(t_asm *info)
{
	int magic;

	magic = 0x00EA83F3;
	ft_write_int(magic, info->fd_cor);
	ft_write_name(info->name, info->fd_cor);
	ft_write_int(0, info->fd_cor);
	ft_write_int(info->pos, info->fd_cor);
	ft_write_comment(info->comment, info->fd_cor);
	ft_write_int(0, info->fd_cor);
//	ft_create_champ(info);
	ft_write_champ(info);
}
