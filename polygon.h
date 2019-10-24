/* poligon.h */

#ifdef polygon_h
#define polygon_h

typedef struct poligono{
	int p;
	int pontos[p];
}poligono;

void desenha_poligono(poligono poligono_desenho);

#endif