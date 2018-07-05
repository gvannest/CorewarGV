#include "corewar.h"

void		ft_reinit_param(t_arena *arena, t_proc *proc)
{
	arena->nb_cycle_current = 0;
	arena->nb_live_currt = 0;
	while (proc)
	{
		proc->nb_live_curr_cycle = 0;
		proc = proc->next;
	}
}
