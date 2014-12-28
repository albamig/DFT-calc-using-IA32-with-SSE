#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 1024
#define PI 3.14
#define ANGULO(j, k) (((-2*PI)/TAM)*(j)*(k)) 

double f_real(int j);
double f_imagin(int j);

typedef struct {
	double real;
	double imaginario;
} complex;

complex x[TAM];

int main() {
	int i;
	srand48(time(NULL));
	for (i = 0; i < TAM; i++) {
		x[i].real = (drand48() * 100) - 50;
		x[i].imaginario = (drand48() * 100) - 50;
	}

	for (i = 0; i < TAM; i++) {
		printf("Indice: %d \t|\t Numero: (%lf)+(%lf)i \t|\t Transformada: (%lf)+(%lf)i\n", 
				i, x[i].real, x[i].imaginario, f_real(i), f_imagin(i));
	}

	return 0;
}

double f_real(int j) {
	int i;
	double freal = 0;
	for (i = 0; i <= j; i++) {
		freal += x[i].real * cos(ANGULO(j, i)) - x[i].imaginario * sin(ANGULO(j, i));
	}

	return freal;
}

double f_imagin(int j) {
	int i;
	double fimagin = 0;
	for (i = 0; i <= j; i++) {
		fimagin += x[i].real * sin(ANGULO(j, i)) + x[i].imaginario * cos(ANGULO(j, i));
	}

	return fimagin;
}