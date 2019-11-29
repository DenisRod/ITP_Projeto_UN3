#include "color.h"


color processa_cor(char c[20]){
	/* Recebe um vetor char(linha do arquivo) vindo do main e faz a tratativa
		por um delimitador de espaço, armazenando na struct color*/
	char *token_cor;
	color C;
	token_cor = strtok(c," ");
	C.R = atoi(strtok(NULL, " "));
	C.G = atoi(strtok(NULL, " "));
	C.B = atoi(strtok(NULL, " "));
	return C;
}
