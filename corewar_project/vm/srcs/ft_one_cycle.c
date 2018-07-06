#include "corewar.h"

void			ft_one_cycle(t_arena *arena, t_proc *proc)
{
	while (proc)
	{
		if (proc->nb_cycle_before_op != 0)
			proc->nb_cycle_before_op--;
		else
		{
			if (proc->opcode_act == op_tab[0].opcode && proc->opcode_valid == 1)
				ft_live(arena, proc);//tableau de pointeur sur fonction en fonction opcode stocke dans processus
			ft_move_process(arena->map_process, proc, -1);
			ft_next_opcode(arena, arena->list_proc);
		}
		proc = proc->next;
	}
	arena->nb_cycle++;
	arena->nb_cycle_current++;
}

