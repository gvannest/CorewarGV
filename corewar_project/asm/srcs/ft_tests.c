#include "asm.h"

static	void	ft_test_is_reg()
{
	//Gautier est lourd dans leau
	printf("is '%s' a reg ? => %d \n", "r10", ft_is_reg("r10"));
	printf("is '%s' a reg ? => %d \n", "r0", ft_is_reg("r0"));
	printf("is '%s' a reg ? => %d \n", "r15", ft_is_reg("r15"));
	printf("is '%s' a reg ? => %d \n", "r16", ft_is_reg("r16"));
	printf("is '%s' a reg ? => %d \n", "r17", ft_is_reg("r17"));
	printf("is '%s' a reg ? => %d \n", "10", ft_is_reg("10"));
	printf("is '%s' a reg ? => %d \n", "", ft_is_reg(""));
	printf("is '%s' a reg ? => %d \n", "x", ft_is_reg("x"));
	printf("is '%s' a reg ? => %d \n", "x10", ft_is_reg("x10"));
	printf("is '%s' a reg ? => %d \n", "r01", ft_is_reg("r01"));
	printf("is '%s' a reg ? => %d \n", "r-1", ft_is_reg("r-1"));
}

static	void	ft_test_is_dir()
{
	printf("is '%s' a dir_value ? => %d \n", "%10", ft_is_dir("%10"));
	printf("is '%s' a dir_value ? => %d \n", "%", ft_is_dir(""));
	printf("is '%s' a dir_value ? => %d \n", "%0", ft_is_dir("%0"));
	printf("is '%s' a dir_value ? => %d \n", "%2", ft_is_dir("%2"));
	printf("is '%s' a dir_value ? => %d \n", "%3", ft_is_dir("%3"));
	printf("is '%s' a dir_value ? => %d \n", "%", ft_is_dir("%"));
	printf("is '%s' a dir_value ? => %d \n", "%l", ft_is_dir("%l"));
	printf("is '%s' a dir_value ? => %d \n", "%00001", ft_is_dir("%00001"));
}

static	void	ft_test_is_ind()
{
	printf("is '%s' a ind_value ? => %d \n", "10", ft_is_ind("10"));
	printf("is '%s' a ind_value ? => %d \n", "", ft_is_ind(""));
	printf("is '%s' a ind_value ? => %d \n", "0010", ft_is_ind("0010"));
	printf("is '%s' a ind_value ? => %d \n", "-10", ft_is_ind("-10"));
	printf("is '%s' a ind_value ? => %d \n", "%2", ft_is_ind("%2"));
	printf("is '%s' a ind_value ? => %d \n", "a", ft_is_ind("a"));
}


static	void	ft_test_is_label()
{
	printf("is '%s' a label ? => %d \n", ":label", ft_is_label(":label"));
	printf("is '%s' a label ? => %d \n", ":", ft_is_label(":"));
	printf("is '%s' a label ? => %d \n", ":l", ft_is_label(":l"));
	printf("is '%s' a label ? => %d \n", "label", ft_is_label("label"));
	printf("is '%s' a label ? => %d \n", "", ft_is_label(""));
	printf("is '%s' a label ? => %d \n", "%label:", ft_is_label("%label:"));
	printf("is '%s' a label ? => %d \n", "%:label", ft_is_label("%:label"));
	printf("is '%s' a label ? => %d \n", ":label", ft_is_label(":label"));
	printf("is '%s' a label ? => %d \n", "%:label:", ft_is_label("%:label:"));
	printf("is '%s' a label ? => %d \n", ":label:", ft_is_label(":label:"));
	printf("is '%s' a label ? => %d \n", "label:", ft_is_label("label:"));
	printf("is '%s' a label ? => %d \n", "l:", ft_is_label("l:"));
	printf("is '%s' a label ? => %d \n", "%:", ft_is_label("%:"));
	printf("is '%s' a label ? => %d \n", "% :", ft_is_label("% :"));
}

static	void	ft_test_is_op()
{
	printf("is '%s' an operation ? => %d \n", "live", ft_is_op("live"));
	printf("is '%s' an operation ? => %d \n", "ld", ft_is_op("ld"));
	printf("is '%s' an operation ? => %d \n", "st", ft_is_op("st"));
	printf("is '%s' an operation ? => %d \n", "add", ft_is_op("add"));
	printf("is '%s' an operation ? => %d \n", "sub", ft_is_op("sub"));
	printf("is '%s' an operation ? => %d \n", "and", ft_is_op("and"));
	printf("is '%s' an operation ? => %d \n", "or", ft_is_op("or"));
	printf("is '%s' an operation ? => %d \n", "xor", ft_is_op("xor"));
	printf("is '%s' an operation ? => %d \n", "zjmp", ft_is_op("zjmp"));
	printf("is '%s' an operation ? => %d \n", "ldi", ft_is_op("ldi"));
	printf("is '%s' an operation ? => %d \n", "sti", ft_is_op("sti"));
	printf("is '%s' an operation ? => %d \n", "fork", ft_is_op("fork"));
	printf("is '%s' an operation ? => %d \n", "lld", ft_is_op("lld"));
	printf("is '%s' an operation ? => %d \n", "lldi", ft_is_op("lldi"));
	printf("is '%s' an operation ? => %d \n", "lfork", ft_is_op("lfork"));
	printf("is '%s' an operation ? => %d \n", "aff", ft_is_op("aff"));
	printf("is '%s' an operation ? => %d \n", "0", ft_is_op("0"));
	printf("is '%s' an operation ? => %d \n", "", ft_is_op(""));
	printf("is '%s' an operation ? => %d \n", "2", ft_is_op("2"));
	printf("is '%s' an operation ? => %d \n", "ab", ft_is_op("ab"));
	printf("is '%s' an operation ? => %d \n", "jum", ft_is_op("jum"));
	printf("is '%s' an operation ? => %d \n", "zjmpt", ft_is_op("zjmpt"));
	printf("is '%s' an operation ? => %d \n", "tzjmpt", ft_is_op("tzjmpt"));
	printf("is '%s' an operation ? => %d \n", "tzjmp", ft_is_op("tzjmp"));
}

void	ft_test_params()
{

	ft_test_is_reg();
	ft_printf("\n");
	ft_test_is_dir();
	ft_printf("\n");
	ft_test_is_ind();
	ft_printf("\n");
	ft_test_is_op();
	ft_printf("\n");
	ft_test_is_label();
}

