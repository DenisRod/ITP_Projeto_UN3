#include "image.h"
#include "cicle.h"
#include "line.h"

FILE *arquivo_saida;

void processa_save(char c[20],int sequencia[], int tamanho, image I, color Co, line L, circulo Ci, retangulo R){
	/*Processa todas as primitivas apontadas no arquivo de entrada.
	recebe como argumento um char (com a linha do arquivo trazendo o save e nome do arquivo,
	a quantidade de instruções(int tamanho) dentro do arquivo e a sequencia(int sequencia[]) de instruções,
	recebe as structs: image, color,line, circulo e retangulo*/
	char *token_titulo;
	color cor_atual;
	//define a cor atual para ser trabalhada como preto, caso não haja uma cor especificada no arquivo
	cor_atual.R=0;
	cor_atual.G=0;
	cor_atual.B=0;
	//identifica pelo delimitador a primeira sequencia de caracteres antes do espaço
	token_titulo = strtok(c," ");
	//abre o arquivo de saída, nomeando com a segunda sequencia de caracteres (após o espaço)
	arquivo_saida=fopen(strtok(NULL, " "),"wb");
	//usa a quantidade de instruções para o laço for
	for(int i=0;i<tamanho;i++){
		//switch para chamar as funções de acordo com a sequencia no vetor de sequencia
		switch(sequencia[i]){
			case 1:
				/*escreve dentro do arquivo de saída o formato da imagem 
					a altura e largura da imagem(cabeçalho da criação da imagem ppm)*/
				fprintf(arquivo_saida, "%s\n","P6");
				fprintf(arquivo_saida, "%d %d\n",I.altura,I.largura);
				fprintf(arquivo_saida, "%s\n","255");
			case 2:
				/*Atualiza a cor atual*/
				cor_atual.R=Co.R;
				cor_atual.G=Co.G;
				cor_atual.B=Co.B;
			case 3:
			//(clear)nada ainda
			case 4:
			//(rect)nada ainda
			case 5:
			//(circle)nada ainda
			case 6:
			//(polygon)nada ainda
			case 7:
			//(fill)nada ainda
			case 8:
			//(open)nada ainda
			case 9:
			/*chama a função para desenhar a linha passando os 
			argumentos necessários para a função ser executada*/
			desenha_linha(I,L,cor_atual);
		}
	}
	fclose(arquivo_saida);
}