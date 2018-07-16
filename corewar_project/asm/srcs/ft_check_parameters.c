#include "asm.h"

static int	ft_open(char *path)
{
	int	fp;

	fp = 0;
	fp = open(path, O_RDONLY);
	return (fp);
}



int		ft_check_parameters(t_asm *info, char **argv, int argc)
{
	if (argc < 2 || argc > 2 || argv[1] == NULL)
			exit (1);
	else if ((info->fp = ft_open(argv[1])) < 0)
				return (0);
	return (info->fp);
}
