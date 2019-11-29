#include "image.h"


image processa_imagem(char c[20]){
	/* Recebe um vetor char(linha do arquivo)vindo do main e faz a tratativa
		por um delimitador de espaço, armazenando na struct image*/
	char *token_image;
	image I;
	token_image = strtok(c," ");
	I.altura = atoi(strtok(NULL, " "));
	I.largura = atoi(strtok(NULL, " "));
	return I;
}
