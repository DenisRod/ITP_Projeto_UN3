/* line.h */

#ifdef line_h
#define line_h

typedef struct line{
	int x1;
	int x2;
	int y1;
	int y2;
}line;

line processa_linha(char c[20]);

#endif