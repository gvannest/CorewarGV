#include "corewar.h"

static void		ft_move_noocp(int *map_process, t_proc *proc)
{
	if (proc->opcode_act == 0x01)
		proc->pc_act = pc_act + 5;
	else
		proc->pc_act = pc_act + 3;
}

static void		ft_move_ocp(int *map_process, t_proc *proc, char ocp)
{
	unsigned int	i;
	short int		k;
	unsigned char	tab[3];

	i = 0;
	k = 0;
	tab[0] = ocp >> 6 & 0x03;
	tab[1] = ocp >> 4 & 0x03;
	tab[2] = ocp >> 2 & 0x03;
	while (i < 3)
	{
		if (tab[i] == 0x01)
			i = i + 1;
		else if (tab[i] == 0x02)
			i = i + 4 - 2 * op_tab[proc->opcode_act - 1].dir_oct_size;
		else if (tab[i] == 0x03)
			i = i + 2;
		i++;
	}
	proc->pc_act = 1 + i + 1;
}



void			ft_move_process(int *map_process, t_proc *proc, char ocp)
{
	int				k;
	unsigned int	i;

	k = map_process[proc->pc_act];
	map_process[proc->pc_act] = 0;
	if (ocp == 0)
		ft_move_noocp(map_process, proc);
	else
		ft_move_ocp(map_process, proc, ocp);
	map_process[proc->pc_act] = k;
}
