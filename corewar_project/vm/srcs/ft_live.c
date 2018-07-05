#include "corewar.h"

void			ft_live(t_arena *arena, t_proc *proc)
{
	int	p;
	int live_pyr;

	p = 0;
	live_pyr = (int)ft_convert_nbr(&(arena->map[proc->pc_act + 1]), 4);
	while (p < arena->nb_pyrs)
	{
		if (live_pyr == arena->tab_pyr[p].pyr_nbr)
		{
			arena->tab_pyr[p].pyr_nb_live++;
			arena->last_live_pyr = arena->tab_pyr[p].pyr_nbr;
		}
		p++;
	}
	arena->nb_live_currt++;
	arena->nb_live_tot++;
	proc->nb_live_curr_cycle++;
}
