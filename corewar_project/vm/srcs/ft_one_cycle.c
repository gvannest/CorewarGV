#include "corewar.h"

void			ft_one_cycle(t_arena *arena, t_proc *proc)
{
	while (proc)
	{
		if (proc->nb_cycle_before_op != 0)
			proc->nb_cycle_before_op--;
		else
		{
			if (proc->opcode == t_op[0].opcode)
				ft_live(arena, proc);//tableau de pointeur sur fonction en fonction opcode stocke dans processus
			ft_move_process(arena->map_process, proc, 0);
			ft_opcode_act = ....

			//ici venir stocker le nombre de cycles de l'operation suivante dans proc->nb_cycle_before_op
			//+ l'opcode de l'opesuivante
		}
		proc = proc->next;
	}
}

