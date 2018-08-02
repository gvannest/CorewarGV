/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 17:13:06 by srossi            #+#    #+#             */
/*   Updated: 2018/08/01 17:42:31 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_help(void)
{
	printf("NAME\n\t asm -- assemble a champion\n\n");
	printf("SYNOPSIS\n\t asm [-h | -d] [file ...]\n\n");
	printf("DESCRIPTION\n\t For one file of a type \".s\", written with\
the language \'assembly\', the progam translate the file into\
machine code which will be read by our Virtual Machine.\n\n");
	printf("\tThe following options are available:\n\n");
	printf("\t-h\tPrint a help message and exit.\n\n");
	printf("\t-d\tDisplay the champion in machine language if correct.\n\n");
	exit(EXIT_SUCCESS);
}
