#include <circle.h>

void c_quadrante_supEsq(circulo quadrante){
	quadrante.x,quadrante.y,quadrante.raio;

}

circulo processa_circulo(char c[20]){
	/* Recebe um vetor char(linha do arquivo) vindo do main e faz a tratativa
		por um delimitador de espaço, armazenando na struct circulo*/
	char *token_circulo;
	circulo C;
	token_circulo = strtok(c," ");
	C.x = atoi(strtok(NULL, " "));
	C.y = atoi(strtok(NULL, " "));
	C.raio = atoi(strtok(NULL, " "));
	return C;
}