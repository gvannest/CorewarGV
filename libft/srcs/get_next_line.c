/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:38:14 by msicot            #+#    #+#             */
/*   Updated: 2018/04/27 11:52:53 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_line(char *s, char **line)
{
	int		i;

	i = 0;
	if (ft_strlen(s) > 0)
	{
		while (s[i] != '\n' && s[i] != 0)
			++i;
		if (!(*line = ft_strnew(i + 1)))
			return (-1);
		if (!(*line = ft_strncpy(*line, s, i)))
			return (-1);
		if (s[i] == '\0')
			--i;
		if (!(s = ft_strncpy(s, (s + i + 1), ft_strlen(s))))
			return (-1);
		return (1);
	}
	return (0);
}

static char	*ft_read(int fd, char *sfd)
{
	char	*tmp;
	int		ret;
	char	*buf;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZ + 1))))
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZ)) > 0)
	{
		buf[ret] = '\0';
		tmp = sfd;
		if (!(sfd = ft_strjoin(sfd, buf)))
			return (NULL);
		ft_strdel(&tmp);
		if (ft_strchr(buf, '\n') != 0)
			break ;
	}
	ft_strdel(&buf);
	return (sfd);
}

int			get_next_line(const int fd, char **line)
{
	static char *s[OPEN_MAX];
	int			nb;

	if (BUFF_SIZ < 1 || read(fd, NULL, 0) == -1 || fd > OPEN_MAX
			|| line == NULL)
		return (-1);
	if (!(s[fd]))
		if (!(s[fd] = ft_strnew(0)))
			return (-1);
	if (!(s[fd] = ft_read(fd, s[fd])))
		return (-1);
	nb = ft_line(s[fd], line);
	return (nb);
}
