/*circle.h*/
#ifdef circle_h
#define circle_h


typedef struct circulo{
	int x,y,raio;
}circulo;

void c_quadrante_supEsq(circulo quadrante);
void c_quadrante_supDir(circulo quadrante);
void c_quadrante_infEsq(circulo quadrante);
void c_quadrante_infDir(circulo quadrante);
circulo processa_circulo(char c[20])


#endif
