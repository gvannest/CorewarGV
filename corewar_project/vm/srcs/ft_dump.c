#include "corewar.h"

static void	ft_print_champ(t_arena *arena)
{
	int i;
	t_player *tmp;
	i = 0;
	while (i < arena->nb_pyrs)
	{	
		tmp = &arena->tab_pyr[i];
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", tmp->pyr_nbr, tmp->nb_inst,  tmp->pyr_name, tmp->comment);
		++i;
	}
//	* Player 1, weighing 36 bytes, "load and store for test" ("just a basic living prog which loads and stores") !
}

void	ft_dump_mem(t_arena *arena)
{
	int i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	ft_print_champ(arena);
	ft_printf("0x%#04x : ", i);
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)//Dans le sujet -> 32 octet. 64 a remplacer par 32
			ft_printf("%#0.4x : ", i);
		ft_printf("%.2hhx ", arena->map[i]);
		++i;
		if (i % 64 == 0)
			ft_printf("\n");
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
		{
			ft_error_vm(8, "-d must be followed by UNSIGNED INT", NULL, 0);
			exit (0); //Dlete probably
		}
		return (1);
	}
	else
		ft_error_vm(8, "-d must be followed by UNSIGNED INT", NULL, 0);
	return (0);
}
