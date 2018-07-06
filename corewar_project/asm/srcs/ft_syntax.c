#include "asm.h"

int	ft_is_valid_syntax(t_asm *info)
{
	t_token *p_token;

	info->nb_params_left = 0;
	p_token = info->atoken;
	while (p_token)
	{
		if (p_token->type == T_OP)
		{
		//	printf("op_tab param :  %d\n", op_tab[p_token->opcode - 1].nb_params);
			if (info->nb_params_left != 0)
			{
		//		printf("sortie param left > 0\n");
				return (0);
			}
			info->nb_params_left = op_tab[p_token->opcode - 1].nb_params;
			info->last_opcode = p_token->opcode;
			info->cur_param = 0;
		//	printf("init nb_params_left : %d\n", info->nb_params_left);
		}
		else if (p_token->type != T_LAB)
		{
		//	printf("token_name : %s\n", p_token->s_val);
		//	printf("cur_param ==  %d\n", info->cur_param);
		//	printf("param_left == %d\n", info->nb_params_left);
			if (info->nb_params_left <= 0)
			{
			//	printf("sortie param_left == %d et cur_param ==  %d\n", info->nb_params_left, info->cur_param);
				return (0);
			}
			info->nb_params_left--;
			info->cur_param++;
		}
		else if (p_token->type == T_LAB && info->nb_params_left > 0)
			return (0);
		p_token = p_token->next;
	}
	if (info->nb_params_left > 0)
		return (0);
	return (1);
}
