#include "asm.h"
/*
 * Verifie que le mot est bien constitue de char autorise
 *
*/ 
int		ft_is_labelchar(int *ptr, char c)
{
	if (ft_strchr(LABEL_CHARS, c))
			return (1);
	else
	{
		*ptr = 1;
		return (0);
	}

}

int		ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

// SEPARATOR_CHAR = ',' 
int		ft_is_sep(char c)
{
	if (c == SEPARATOR_CHAR)
		return (1);
	return (0);
}

int		ft_is_othchr(char c)
{
	if (c == LABEL_CHAR)
		return (1);
	if (c == DIRECT_CHAR)
		return (1);
	if (c == SEPARATOR_CHAR)
		return (1);
	if (c == '.')
		return (1);
	return (0);
}

int		ft_is_comchar(int *num, char c)
{
	if (c == COMMENT_CHAR)
	{
		*num = 1;
		return (1);
	}
	return (0);
}
