/*circle.h*/
#ifdef circle_h
#define circle_h

int i,j;

typedef struct circulo{
	int x,y;
	float raio;
}circulo;

void c_quadrante_supEsq(circulo quadrante);
void c_quadrante_supDir(circulo quadrante);
void c_quadrante_infEsq(circulo quadrante);
void c_quadrante_infDir(circulo quadrante);


#endif