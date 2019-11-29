#include "line.h"
#include "line.c"


void polygon(int n, point pt[n]){
	for (int i=1; i<n; i++){
		l.p1.x = pt[i-1].x;
		l.p1.y = pt[i-1].y;
		l.p2.x = pt[i].x;
		l.p2.y = pt[i].y;
		line(l);
	}
	l.p1.x = pt[0].x;
	l.p1.y = pt[0].y;
	line(l);
}
