#include <stdio.h>
#include <string.h>
#include<stdlib.h>


int main (){

	FILE *arquivo;
	FILE *arquivo_saida;
	int i =0,contador_colunas=0,dimensoes_imagem[2],flag_imagem=0,cont_dimensoes=0;
	char c[10][200], *token;
	arquivo=fopen("arquivo.txt","r+");
	
	while( fgets(c[i], 200, arquivo) != NULL){
		i++;
	}
	fclose(arquivo);
	arquivo_saida = fopen("image.ppm","w+");
	for(int j=0;j<1;j++){
		printf("linha %d = %s",j,c[j]);
	}
	for(int j=0;j<2;j++){
		token = strtok(c[j]," ");
		while(token != NULL){
			if(strcmp(token,"image")==0){
				contador_colunas++;
				flag_imagem=1;
			}
			else if (flag_imagem==1 && cont_dimensoes<2){
				dimensoes_imagem[cont_dimensoes] = atoi(token);
				printf ("%d",dimensoes_imagem[cont_dimensoes]);
				cont_dimensoes++;
			}
			else if (strcmp(token,"save")==0){
				if(flag_imagem == 0){
					printf("Imagem nao criada!");
				}
			}
			
			token = strtok(NULL, " ");
		}
	}
	fclose(arquivo_saida);
	
	
	return 0;
}
