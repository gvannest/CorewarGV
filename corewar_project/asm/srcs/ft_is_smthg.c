#include "asm.h"

int		ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

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
	return (0);
}
