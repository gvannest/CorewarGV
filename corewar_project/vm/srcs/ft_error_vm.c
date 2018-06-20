/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_vm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:30:00 by gvannest          #+#    #+#             */
/*   Updated: 2018/06/20 18:09:28 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// code == 0 : erreur de open / read / close / malloc. erreur systeme
// code == 1 : Erreur de magic number

void	ft_error_vm(char error_code, char *msg1, char *msg2, int v1)
{
	if (error_code == 0)
	{
		ft_putstr_fd(msg1, 2);
		ft_putstr_fd("Source file : ", 2);
		ft_putstr_fd(msg2, 2);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd(strerror(errno), 2);
	}
	else if (error_code == 1)
	{
		ft_putstr_fd(msg1, 2);
		ft_putstr_fd("Usage : ./corewar -visual [-dump nbr_cycles] ", 2);
		ft_putstr_fd("[[-n number] champion1.cor]...\n", 2);
		ft_putstr_fd("[number] must be different than 0\n", 2);
	}
	else if (error_code == 2)
	{
		ft_putstr_fd(msg1, 2);
		ft_putstr_fd("From file : ", 2);
		ft_putstr_fd(msg2, 2);
		ft_putchar_fd('\n', 2);
		ft_putnbr_fd(v1, 2);
		ft_putstr_fd(" != ", 2);
		ft_putnbr_fd(COREWAR_EXEC_MAGIC, 2);
	}
	else if (error_code == 3)
	{
		ft_putstr_fd(msg1, 2);
		ft_putstr_fd("Minimum number of players : 1\n", 2);
		ft_putstr_fd("Maximum number of players : ", 2);
		ft_putnbr_fd(MAX_PLAYERS, 2);
		ft_putchar_fd('\n', 2);
	}
	else if (error_code == 4)
	{
		ft_putstr_fd(msg1, 2);
		ft_putstr_fd("From file : ", 2);
		ft_putstr_fd(msg2, 2);
		ft_putchar_fd('\n', 2);
		if (v1 == 1)
		{
			ft_putstr_fd("Maximum champion's name size : ", 2);
			ft_putnbr_fd(PROG_NAME_LENGTH, 2);
		}
		else
		{
			ft_putstr_fd("Maximum comment size : ", 2);
			ft_putnbr_fd(COMMENT_LENGTH, 2);
		}
		ft_putstr_fd(" bytes\n", 2);
	}
	else if (error_code == 5)
	{
		ft_putstr_fd(msg1, 2);
		ft_putstr_fd("From file : ", 2);
		ft_putstr_fd(msg2, 2);
		ft_putchar_fd('\n', 2);
		ft_putnbr_fd(v1, 2);
		ft_putstr_fd(" bytes vs. [1, ", 2);
		ft_putnbr_fd(CHAMP_MAX_SIZE, 2);
		ft_putstr_fd("] bytes\n", 2);
	}
	else if (error_code == 6)
	{
		ft_putstr_fd(msg1, 2);
		ft_putstr_fd("From file : ", 2);
		ft_putstr_fd(msg2, 2);
		ft_putchar_fd('\n', 2);
		if (v1 == 1)
			ft_putstr_fd("between name and number of instructions - ", 2);
		else
			ft_putstr_fd("between comment and instructions - ", 2);
		ft_putstr_fd(msg2, 2);
		ft_putchar_fd('\n', 2);
	}
	exit(EXIT_FAILURE);
}
