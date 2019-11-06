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
	int i =0,j,k,dimensoes_imagem[2],flag_imagem=0,cont_dimensoes=0;
	char c[10][200], *token;
	arquivo=fopen("arquivo.txt","r+");
	
	while( fgets(c[i], 200, arquivo) != NULL){
		i++;
	}
	fclose(arquivo);
	arquivo_saida = fopen("image.ppm","wb");
	for(j=0;j<10;j++){
		token = strtok(c[j]," ");
		while(token != NULL){
			if(strcmp(token,"image")==0){
				flag_imagem=1;
				fprintf(arquivo_saida, "%s","P6\n");
			}
			else if (flag_imagem==1 && cont_dimensoes<2){
				dimensoes_imagem[cont_dimensoes] = atoi(token);
				fprintf(arquivo_saida, "%s ",token);
				cont_dimensoes++;
			}
			else if(cont_dimensoes==2){
				fprintf(arquivo_saida,"%s","\n255\n");
				for(i=0; i<dimensoes_imagem[0];i++){
					for(k=0;k<dimensoes_imagem[1];k++){
					      static unsigned char color[3];
					      color[0] = i % 256; /*R*/
					      color[1] = k % 256; /*G*/
					      color[2] = (i * k) % 256;/*B*/ 
					      (void) fwrite(color, 1, 3, arquivo_saida);
					}
				}
			}

			else if (strcmp(token,"save")==0){
				if(flag_imagem == 0){
					printf("Imagem nao criada!");
				}
			}
			//Possíveis RETA E POLÍGONO
			/*
			else if (strcmp(token,"line")==0){
				fscanf(arquivo, "line %s %s %s %s", &x1, &y1, &x2, &y2);
			}
			else if (strcmp(token,"polygon")==0){
				fscanf(arquivo, "polygon %s ", &lados);
				i=0;
				while (i<(lados*2)){
					fscanf(arquivo, "%s ",&vertice[i]);
					i++;
				}
			}
			*/
			
			
			token = strtok(NULL, " ");
		}
	}
	fclose(arquivo_saida);
	
	
	return 0;
}
