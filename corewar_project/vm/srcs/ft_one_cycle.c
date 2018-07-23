#include "corewar.h"
#include "tab_functions.h"

void			ft_one_cycle(t_arena *arena, t_proc *proc)
{
	int	i;

	while (proc)
	{
		if (proc->nb_cycle_before_op != 0)
			proc->nb_cycle_before_op--;
		else
		{
			i = 0;
			while (i < 9)
			{
				if (proc->opcode_act == g_tab_function[i].o && proc->opcode_valid == 1)
				{
					g_tab_function[i].f_inst(arena, proc);
					break;
				}
				i++;
			}
			if (proc->jump != 1)
				ft_move_process(arena->map_process, proc, proc->ocp);
			ft_next_opcode(arena, proc);
			ft_reinit_param(proc);
		}
		proc = proc->next;
	}
}

