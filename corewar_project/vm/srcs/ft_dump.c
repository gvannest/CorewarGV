#include "corewar.h"

void	ft_dump_mem(t_arena *arena)
{
	int i;

	i = 0;
//	ft_printf("0x%d: ", i);
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			ft_printf("0x%d: ", i);
		}
		ft_printf("%.2hhx ", arena->map[i]);
		if (i % 63 == 0)
			ft_printf("\n");
		++i;
	}
}

int		ft_dump(t_arena *arena, char **argv, int argc, int i)
{
	if (i + 1 >= argc)
		return (0);
	if (ft_isnum(argv[i + 1]))
	{
		arena->dump_f = 1;
		arena->dump_nb = ft_atoi(argv[i + 1]);
		if (arena->dump_nb < 0)
			ft_error_vm(8, "-d must be followed by UNSIGNED INT", NULL, 0);
		return (1);
	}
	else
		ft_error_vm(8, "-d must be followed by UNSIGNED INT", NULL, 0);
	return (0);
}
