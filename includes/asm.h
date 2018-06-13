/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:53:35 by srossi            #+#    #+#             */
/*   Updated: 2018/06/13 18:55:28 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

typedef struct s_asm
{
	char 	*tab;
	struct 	*label;
}			  t_asm;

typedef struct s_label
{
	char 	*name;
	struct	*s_instruction;
	int		address;

}
