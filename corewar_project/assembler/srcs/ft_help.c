#include "asm.h"

void	ft_help()
{
	printf("NAME\n\t asm -- assemble a champion\n\n");
	printf("SYNOPSIS\n\t asm [-h | -d] [file ...]\n\n");
	printf("DESCRIPTION\n\t For one file of a type \".s\", written with the language \'assembly\', the progam translate the file into machine code which will be read by our Virtual Machine.\n\n");
	printf("\tThe following options are available:\n\n");
	printf("\t-h\tPrint a help message and exit.\n\n");
	printf("\t-d\tDisplay the champion in machine language if correct.\n\n");
	exit(EXIT_SUCCESS);
}
