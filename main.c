#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*typedef struct image{
	int altura;
	int largura;
	int dimensoes_imagem[2];
	int cont_dimensoes;
}image; */

int main (){

	FILE *arquivo;
	FILE *arquivo_saida;
	int i =0,j,dimensoes_imagem[2],flag_imagem=0,cont_dimensoes=0;
	char c[10][200], *token;
	arquivo=fopen("arquivo.txt","r+");
	
	while( fgets(c[i], 200, arquivo) != NULL){
		i++;
	}
	fclose(arquivo);
	arquivo_saida = fopen("image.ppm","w+");
	for(j=0;j<10;j++){
		token = strtok(c[j]," ");
		while(token != NULL){
			if(strcmp(token,"image")==0){
				flag_imagem=1;
				fprintf(arquivo_saida, "%s\n","P3");
			}
			else if (flag_imagem==1 && cont_dimensoes<2){
				dimensoes_imagem[cont_dimensoes] = atoi(token);
				fprintf(arquivo_saida, "%s ",token);
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
