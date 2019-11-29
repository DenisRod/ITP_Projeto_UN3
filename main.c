#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.c"
#include "line.h"
#include "image.h"
#include "image.c"
#include "circle.h"
#include "circle.c"
#include "rect.h"
#include "rect.c"
#include "polygon.h"
#include "polygon.c"
#include "color.h"
#include "color.c"


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