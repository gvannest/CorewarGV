/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:18:30 by srossi            #+#    #+#             */
/*   Updated: 2018/01/29 15:15:21 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c_tmp;

	if (str)
	{
		i = 0;
		j = ft_strlen(str) - 1;
		while (i < j)
		{
			c_tmp = str[i];
			str[i] = str[j];
			str[j] = c_tmp;
			i++;
			j--;
		}
	}
	return (str);
}
