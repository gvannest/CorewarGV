#include "asm.h"

static void	init_info(t_asm *info)
{
	//coucou gautier
	
	info->name_f = 0;
	info->comment_f = 0;
	ft_bzero(info->name, PROG_NAME_LENGTH + 1 );
	ft_bzero(info->comment, COMMENT_LENGTH + 1);
	info->line_nb = 0;
	info->error = 0;
	info->err_pos = -1;
}
/*
static	void ft_test_clean_label()
{
	printf("%s\n", ft_clean_label("label1"));
	printf("%s\n", ft_clean_label("%:label1"));
	printf("%s\n", ft_clean_label(":label1"));
	printf("%s\n", ft_clean_label("label1:"));
	printf("%s\n", ft_clean_label("%label1"));
	printf("%s\n", ft_clean_label("label1%"));
}
*/



void	ft_test_label()
{
	t_asm info2;

	ft_bzero(&info2, sizeof(t_asm));
	init_info(&info2);
	printf("Entree test label\n");
	ft_token_add(&info2, "2"); //remplacer par l'arg de Martin
	ft_token_add(&info2, "lld"); //remplacer par l'arg de Martin
	ft_token_add(&info2, "r1"); //remplacer par l'arg de Martin
	ft_token_add(&info2, "r2"); //remplacer par l'arg de Martin
	ft_token_add(&info2, "label42:"); //remplacer par l'arg de Martin
	ft_token_add(&info2, "%1"); //remplacer par l'arg de Martin
	ft_token_add(&info2, "%:live"); //remplacer par l'arg de Martin
	ft_token_display_all(info2.atoken);
//	printf("%d\n", ft_find_label(info2.atoken, "live:")->pos);
//	printf("%d\n", ft_find_label(info2.atoken, "label42:")->pos);
	ft_fill_labels(info2.atoken);
	ft_token_display_all(info2.atoken);
	printf("Sortie test label\n");
//	ft_test_clean_label();
}
