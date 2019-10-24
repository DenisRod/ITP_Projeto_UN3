/*circle.h*/
#ifdef circle_h
#define circle_h

int i,j;

typedef struct circulo{
	int x,y;
	float raio;
}circulo;

void c_octante_supEsq(circulo octante);
void c_octante_supDir(circulo octante);
void c_octante_infEsq(circulo octante);
void c_octante_infDir(circulo octante);


#endif