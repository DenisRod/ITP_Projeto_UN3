#include "line.h"

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

void line(Line l){
  
	int dx, dy, dm, x, y;
	dx=x1-x0;
	dy=y1-y0;
	x=x0;
	y=y0;
	dm=2*dy-dx;
  	if(x<x1){
		while(x<x1){
      			if(dm>=0){
        		setPixel(x,y,color);
      			y=y+1;
     			dm=dm+2*dy-2*dx;
      			}
      			else{
        		setPixel(x,y,color);
        		dm=dm+2*dy;
      			}
      		x=x+1;
    		}
  	}
  	else{
    		while(x>x1){
      			if(dm>=0){
        		setPixel(x,y,color);
        		y=y+1;
        		dm=dm+2*dy-2*dx;
      			}
      			else{
        		setPixel(x,y,color);
        		dm=dm+2*dy;
      			}
      			x=x-1;
    		}
  	}
}

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
