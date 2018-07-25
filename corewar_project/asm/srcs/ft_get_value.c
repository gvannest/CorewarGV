/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:20:50 by srossi            #+#    #+#             */
/*   Updated: 2018/07/19 17:39:09 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*int	ft_get_ival(char *arg)
{
	int ival;
	int index;

	ival = 0;
	index = 0;
	while (index < NB_INSTR && (ft_strcmp(op_tab[index].name, arg) != 0))
		index++;
	if (index < NB_INSTR)
		ival = op_tab[index].opcode;
	return (ival);
}*/

int	ft_get_opcode(char *arg)
{
	int index;

	index = 0;
	while (index < NB_INSTR)
	{
		if (ft_strcmp(op_tab[index].name, arg) == 0)
			return (op_tab[index].opcode);
		index++;
	}
	return (-1);
}

int	ft_get_type(char *arg)
{
	int	type;

	type = 0;
	if (ft_is_reg(arg) > 0)
		type = T_REG;
	else if (ft_is_dir(arg) > 0)
		type = T_DIR;
	else if (ft_is_ind(arg) > 0)
		type = T_IND;
	else if (ft_is_op(arg) > 0)
		type = T_OP;
	else
		type = ft_is_label(arg);
//	printf("arg : %s\n", arg);
//	printf("type : %d\n", type);
	return (type);
}
