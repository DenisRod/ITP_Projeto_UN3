#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *arquivo_saida;

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

image processa_imagem(char c[20]){
	char *token_image;
	image I;
	token_image = strtok(c," ");
	I.altura = atoi(strtok(NULL, " "));
	I.largura = atoi(strtok(NULL, " "));
	return I;
}
color processa_cor(char c[20]){
	char *token_cor;
	color C;
	token_cor = strtok(c," ");
	C.R = atoi(strtok(NULL, " "));
	C.G = atoi(strtok(NULL, " "));
	C.B = atoi(strtok(NULL, " "));
	return C;
}
line processa_linha(char c[20]){
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
	char *token_circulo;
	circulo C;
	token_circulo = strtok(c," ");
	C.x = atoi(strtok(NULL, " "));
	C.y = atoi(strtok(NULL, " "));
	C.raio = atoi(strtok(NULL, " "));
	return C;
}

void desenha_linha(image I,line L,color C){
	int i,j,inclinacao;
	inclinacao = (L.y2-L.y1)/(L.x2-L.x1);
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
	}
}

void processa_save(char c[20],int sequencia[], int tamanho, image I, color Co, line L, circulo Ci, retangulo R){
	
	char *token_titulo;
	color cor_atual;
	cor_atual.R=0;
	cor_atual.G=0;
	cor_atual.B=0;

	token_titulo = strtok(c," ");
	arquivo_saida=fopen(strtok(NULL, " "),"wb");

	for(int i=0;i<tamanho;i++){
		switch(sequencia[i]){
			case 1:
				fprintf(arquivo_saida, "%s\n","P6");
				fprintf(arquivo_saida, "%d %d\n",I.altura,I.largura);
				fprintf(arquivo_saida, "%s\n","255");
			case 2:
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
			desenha_linha(I,L,cor_atual);
		}
	}
	fclose(arquivo_saida);
}

int main (){

FILE *arquivo;

char c[10][200],*token;
int i=0,j;
image Im;
line Li;
circulo Ci;
retangulo Re;
color Co;

arquivo=fopen("arquivo.txt","r+");

while( fgets(c[i], 200, arquivo) != NULL){
	i++;
}
int sequencia[i];
/*
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