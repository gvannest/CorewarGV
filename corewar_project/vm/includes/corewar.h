/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:52:06 by gvannest          #+#    #+#             */
/*   Updated: 2018/07/24 11:58:27 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "get_next_line.h"
# include "corewar_visual.h"
// ATTENTION : chaque .h dans include doit etre justifie. mettre les autres .h dans les .c ou ils sont utilises. les .h ici doivent etre utilises dans ce .h!!!!

typedef struct		s_player
{
	char			pyr_name[PROG_NAME_LENGTH + 1];
	int				pyr_nbr;
	int				nb_inst;
	int				color_pyr;
	char			champ[CHAMP_MAX_SIZE + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	pyr_nb_live;//nb de live executes sur ce joueur
}					t_player;

typedef struct		s_arena
{
	char			map[MEM_SIZE + 1];//l' arene de jeu
	int				map_pyr[MEM_SIZE];// idem mais avec num pyr pour visu
	int				map_process[MEM_SIZE];// idem mais avec process pour visu
	unsigned int	nb_cycle; //nb de cycles depuis debut partie
	unsigned int	nb_cycle_current;//nb cycles current period (<= cycle-to-die)
	unsigned int	cycle_to_die;// idem op.h
	unsigned int	nb_live_currt;//nb de vies dans le cycle courant
	unsigned int	nb_live_tot;//nb de vies totales depuis debut partie
	unsigned int	nb_live_proc;// nb processus en vie
	unsigned int	nb_round_no_decrease;;// nb de round (cycle to die) without decreasing CYCLE TO DIE
	int				nb_pyrs;
	int				last_live_pyr;//dernier joueru a avoir dit " vie" 
	t_player		tab_pyr[MAX_PLAYERS];// tableau des joueurs
	struct s_proc	*list_proc;//pointeur vers debut liste chainee processus
}					t_arena;

typedef struct		s_param
{
	int				value;
	char			size;
	char			type;
}					t_param;

typedef struct		s_proc
{
	short int		p_nbr;
	int				reg[REG_NUMBER];
	short int		pc_act;//adresse actuelle du processus
	short int		pc_next;//adresse de la prochaine operation
	char			opcode_act; //opcode de l'operation en cours
	char			opcode_valid; //flag pour dire si opcode valide
	unsigned int	nb_cycle_before_op;//nb de cycles restant avant executier et bouger
	unsigned int	nb_live_curr_cycle;//nb de lives executees sur le cycle courant
	char			carry;
	char			jump;
	char			ocp;
	t_param			tab_param[3];
	struct s_proc	*parent;
	struct s_proc	*son;
	struct s_proc	*next;
}					t_proc;

typedef struct s_op
{  
	char	*name;
	int		nb_params;
	char	param_type[MAX_ARG];
	char 	opcode;
	int		nb_cycles;
	char	*description;
	int 	mod_carry;
	int		dir_oct_size; //0 = 4 octets et 1 = 2 octets
}				t_op;

extern t_op op_tab[NB_INSTR + 1];

void				ft_error_vm(char code, char *msg1, char *msg2, int v1);
void				ft_parse_vm1(char *line, t_arena *arena, char *cor, int i);
void				ft_parse_vm2(char *line, t_arena *arena, char *cor, int i);
char				ft_arguments(int argc, char **argv, t_arena *arena);
void				ft_assert(char *line, t_arena *arena);
int					ft_isnum(char *str);
void				ft_fill_game(t_arena *arena);
void				ft_init_process(t_arena *arena);
void				ft_visual(t_arena *arena, t_corvisu *visual);
void				ft_init_visual(t_corvisu *visual);
void				ft_is_proc(t_corvisu *visual, int pyr_idx, char inst, int i);
void				ft_is_not_proc(t_corvisu *visual, int pyr_idx, char inst, int i);
void				ft_info_game(t_arena *arena, t_corvisu *visual);
void				ft_info_fix(t_player *tab_pyr, int nb_pyrs, t_corvisu *visual);
void				ft_info_player(t_player *tab_pyr, int nb_pyrs, t_corvisu *visual);
void				ft_game(t_arena *arena, t_corvisu *visual, char v);
void				ft_check_cycle(t_arena *arena);
t_proc				*ft_kill_process(t_proc **begin_list, t_proc *proc_to_kill);
void				ft_reinit_cycle(t_arena *arena, t_proc *proc);
void				ft_reinit_param(t_proc *proc);
void				ft_next_opcode(t_arena *arena, t_proc *proc);
void				ft_one_cycle(t_arena *arena, t_proc *proc);
void				ft_move_process(int *map_process, t_proc *proc, char ocp);
int					ft_get_param(t_arena *arena, t_proc *proc, int pc, char dir_size);

void				ft_live(t_arena *arena, t_proc *proc);
void				ft_load(t_arena *arena, t_proc *proc);
void				ft_store(t_arena *arena, t_proc *proc);
void				ft_add(t_arena *arena, t_proc *proc);
void				ft_sub(t_arena *arena, t_proc *proc);
void				ft_and(t_arena *arena, t_proc *proc);
void				ft_or(t_arena *arena, t_proc *proc);
void				ft_xor(t_arena *arena, t_proc *proc);
void				ft_zjmp(t_arena *arena, t_proc *proc);

unsigned long		ft_read_memory(char *map, int start, size_t k);
void				ft_write_memory(char *map, unsigned int v, int start, size_t k);
void				ft_update_map_pyr(int *map_pyr, int pc_act, int start, size_t k);
int					ft_check_ocp(t_param *tab, char *p1, char *p2, char *p3);
void				ft_index_idxmod(int *k, int value, int pc_act);

void				ft_free_listproc(t_proc *begin_list);

void				ft_print_test(char *line);

#endif



