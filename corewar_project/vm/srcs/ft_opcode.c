#include "corewar.h"

static void		ft_check_opcode(t_proc *proc)
{
	int i;

	i = 0;
	while (i < 15)
	{
		if (proc->opcode_act == op_tab[i].opcode)
		{
			proc->opcode_valid = 1;
			proc->nb_cycle_before_op = op_tab[i].nb_cycles;;
			return;
		}
		i++;
	}
}

void		ft_next_opcode(t_arena *arena, t_proc *proc)
{
	proc->opcode_act = arena->map[proc->pc_act];
	ft_check_opcode(proc);
}

