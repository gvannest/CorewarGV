/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:39:27 by srossi            #+#    #+#             */
/*   Updated: 2018/08/02 11:32:31 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_init_info(t_asm *info)
{
	info->last_opcode = -1;
	info->err_pos = -1;
	info->nb_params = 0;
	info->size = 1;
	info->last_op_line = -1;
}
