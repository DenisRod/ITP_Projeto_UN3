#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* arquivo de saída declarado global para ser acessado em 
qualquer função*/
FILE *arquivo_saida;

// Inicio declaração das structs
typedef struct image{
	int altura;
	int largura;
}image;

typedef struct color{
	int R;
	int G;
	int B;
}color;

typedef struct line{
	int x1;
	int x2;
	int y1;
	int y2;
}line;

typedef struct poligono{
	int p;
	int pontos[100];
}poligono;

typedef struct retangulo{
	int x,y,altura,largura;
}retangulo;

typedef struct circulo{
	int x,y,raio;
}circulo;

// Fim declaração das structs

//Inicio funções de tratamento do arquivo de entrada (.txt)

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
line processa_linha(char c[20]){
	/* Recebe um vetor char(linha do arquivo) vindo do main e faz a tratativa
		por um delimitador de espaço, armazenando na struct line*/
	char *token_line;
	line L;
	token_line = strtok(c," ");
	L.x1 = atoi(strtok(NULL, " "));
	L.y1 = atoi(strtok(NULL, " "));
	L.x2 = atoi(strtok(NULL, " "));
	L.y2 = atoi(strtok(NULL, " "));
	return L;
}
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
// Fim das funções de tratamento do arquivo

void desenha_linha(image I,line L,color C){
	/* Função para desenhar a linha dentro da struct image
	com a cor definida como atual nos pontos salvos na struct line;
	Recebe uma struct image(altura e largura da iamgem),
	 uma struct color(as cores definidas no arquivo) e uma struct line.*/
	int i,j,inclinacao;
	//calculo da inclação da linha;
	inclinacao = (L.y2-L.y1)/(L.x2-L.x1);
	/* 
	if(L.x1 <=I.largura && L.x2 <=I.largura && L.y1<=I.altura && L.y2<=I.altura){
		for(i=0;i<I.altura;i++){
			for(j=0;j<I.largura;j++){				
				static unsigned char color[3];
				color[0] = C.R;
				color[1] = C.G; 
				color[2] = C.B;
				(void) fwrite(color, 1, 3, arquivo_saida);
			}
		}
	}
	else{
		printf("Dimensoes fora do tamanho da imagem\n");
	}*/
}

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

int main (){
//Declaração do arquivo de entrada
FILE *arquivo;
/*Declaração das variáveis utilizadas:
char[][] - declarado para receber as linhas do arquivo 
char *token - para armazenar o separador/delimitador
int i para contar as linhas
int j para o laço for
Im,Li,Ci,Re e Co as structs de image, line, circulo, retangulo e cor*/
char c[10][200],*token;
int i=0,j;
image Im;
line Li;
circulo Ci;
retangulo Re;
color Co;
//abertura do arquivo de entrada para leitura
arquivo=fopen("arquivo.txt","r+");

while( fgets(c[i], 200, arquivo) != NULL){
	i++;
} 
int sequencia[i];
/*
atribuição numerica para cada função ser chamada na função de save
image = 1;
color = 2;
clear = 3;
rect = 4;
circle = 5;
polygon = 6;
fill = 7;
open = 8;
line = 9;
*/
fclose(arquivo);

/*Percorre todas as posições da matriz de char, onde cada posição
representa uma linha do arquivo de entrada, e como no começo de cada
nova linha o primeiro termo sempre será o comando a ser executado,
realiza uma comparação das inicias para, assim, indentificá-lo, após isso
chama a função para executar o processsamento da cadeia de caracteres*/
for(j=0;j<i;j++){
	if (c[j][0] == 'i' && c[j][1] == 'm'){
		Im = processa_imagem(c[j]);
		sequencia[j]=1;
	}
	else if (c[j][0] == 'c' && c[j][1] == 'o'){
		Co = processa_cor(c[j]);
		sequencia[j]=2;
	}
	else if (c[j][0] == 'l' && c[j][1] == 'i'){
		Li = processa_linha(c[j]);
		sequencia[j]=9;
	}
	else if (c[j][0] == 'c' && c[j][1] == 'i'){
		Ci = processa_circulo(c[j]);
		sequencia[j]=5;
	}
	else if (c[j][0] == 'r' && c[j][1] == 'e'){
		Re = processa_retangulo(c[j]);
		sequencia[j]=4;
	}
	else if (c[j][0] == 's' && c[j][1] == 'a'){
		processa_save(c[j],sequencia,i,Im,Co,Li,Ci,Re);
	}
}
return 0;
}