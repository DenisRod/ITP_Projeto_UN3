/* image.h */

#ifdef image_h
#define image_h

typedef struct image{
	int altura;
	int largura;
	char aux[altura][largura];
}image;

image processa_imagem(char c[20]);

#endif
