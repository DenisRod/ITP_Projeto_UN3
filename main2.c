#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct image{
	int altura;
	int largura;
}image;

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
	int x,y;
	float raio;
}circulo;


int main (){

FILE *arquivo;
FILE *arquivo_saida;
char c[10][200],*token;
int i,j,k,l;

arquivo=fopen("arquivo.txt","r+");

while( fgets(c[i], 200, arquivo) != NULL){
	i++;
}
printf("linhas = %d",i);
for(j=0;j<i;j++){
		token = strtok(c[j]," ");
		while(token != NULL){
			if(strcmp(token,"image")==0){
				image I;
				fscanf(arquivo,"image %s %s", &I.altura, &I.largura);
				printf("%d\n",I.altura );
			}
			else if (strcmp(token,"save")==0){
				
			}

			else if (strcmp(token,"open")==0){
			
			}
			else if(strcmp(token,"line")==0){
				line L;
				fscanf(arquivo,"line %d %d %d %d", &L.x1, &L.x2, &L.y1,&L.y2);
			}
			else if(strcmp(token,"rect")==0){
				retangulo R;
				fscanf(arquivo,"rect %s %s %s %s", &R.x, &R.y, &R.altura,&R.largura);
			}

			token = strtok(NULL, " ");
		}
	}

return 0;
}