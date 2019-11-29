#include "rect.h"


retangulo processa_retangulo(char c[20]){
	/* Recebe um vetor char(linha do arquivo) vindo do main e faz a tratativa
		por um delimitador de espaço, armazenando na struct retangulo*/
	char *token_retangulo;
	retangulo R;
	token_retangulo = strtok(c," ");
	R.x = atoi(strtok(NULL, " "));
	R.y = atoi(strtok(NULL, " "));
	R.altura = atoi(strtok(NULL, " "));
	R.largura = atoi(strtok(NULL, " "));
	return R;
}
