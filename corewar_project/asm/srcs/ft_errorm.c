/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:25:26 by msicot            #+#    #+#             */
/*   Updated: 2018/07/17 10:35:54 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/* La gestion d'erreurs
 *
 * Il faut s'arreter au bon moment tout en conservant le dernier mot parsed
 * s'il ne correspond pas a ce qui etait attendu
 *
 */

/* Type d'erreurs
 *	ENDLINE : lorsque un char particulier etait attendu sur la meme ligne et 
 *	le parseur a atteint la fin de la ligne
 *
 *	END : un char attentu avant la fin du fichier, et le parseur n'a rien trouve
 *
 *	SEPARATOR : SEPARATOR a la mauvaise place
 *
 *	INSTRUCTION : instruction non reconnu ou pas la bonne place
 *
 *	COMMAND_COMMENT/NAME : commande reconnu mais pas a la bonne place
 *
 *
 *
 */
 
void	command_name_error(t_asm *info, char *arg)
{
	info->error = 2;
	//	ft_printf("cmd name error\n");
	parsing_error(info, arg);
	exit (1);
}

void	ft_error_management(t_asm *info, char *arg)
{
	if (info->comma_f == 1 && info->nb_comma == info->nb_param)
		info->error = 1;
	else if (info->lock == 1 && (info->comment_f == -1 || info->name_f == -1))
	{
		if (info->quote == 0)
		{
			info->error = (info->name_f == -1 || info->comment_f == -1) ? 4 : 2;
			parsing_error(&(*info), arg);
		}
	}
}
