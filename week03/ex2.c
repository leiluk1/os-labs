#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float x;
	float y;
} Point;

float distance(Point A, Point B){
	float result;
	result = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
	return result;
}

float area(Point A, Point B, Point C){
	float result;
	result = 0.5 * fabs(A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - A.x * C.y);
	return result;
}

int main(void){
	Point A;
	Point B;
	Point C;
	A.x = 2.5;
	A.y = 6;
	B.x = 1;
	B.y = 2.2;
	C.x = 10;
	C.y = 6;
		

	float f = distance(A, B);
	printf("A -- B distance is %f\n", f);


	float a = area(A, B, C);
	printf("Area of triangle ABC is %f\n", a);

	return EXIT_SUCCESS;
}
