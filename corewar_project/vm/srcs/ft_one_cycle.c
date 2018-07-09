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
			ft_move_process(arena->map_process, proc, -1);// attention dernier element OPC a gerer mieux que ca
			ft_next_opcode(arena, proc);
		}
		proc = proc->next;
	}
}

