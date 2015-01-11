#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define TAM 1024
#define ANGULO(j, k) (((-2*M_PI)/TAM)*(j)*(k)) 

void dftc();
void dftsse();
void imprime_resul();

double val_complex[TAM][2];
double res_complex[TAM][2];

int main() {
	int i;
	srand48(time(NULL));
	for (i = 0; i < TAM; i++) {
		val_complex[i][0] = (drand48() * 100) - 50;
		val_complex[i][1] = (drand48() * 100) - 50;
	}
	clock_t start_c, fin_c, start_sse, fin_sse;
	start_c = clock(); 
	dftc();
	fin_c = clock();
	imprime_resul();
	start_sse = clock();
	dftsse();
	fin_sse = clock();
	printf("Tiempo C: %f\nTiempo SSE: %f\n", 
		((double)fin_c - (double)start_c)/CLOCKS_PER_SEC, ((double)fin_sse - (double)start_sse)/CLOCKS_PER_SEC);
	return 0;
}

void dftc() {
	int i, j;
	double res_real, res_imagin;

	for (i = 0; i < TAM; i++) {
		res_real = 0;
		res_imagin = 0;

		for (j = 0; j < TAM; j++) {
			res_real += val_complex[j][0] * cos(ANGULO(i, j)) - val_complex[j][1] * sin(ANGULO(i, j));
			res_imagin += val_complex[j][0] * sin(ANGULO(i, j)) + val_complex[j][1] * cos(ANGULO(i, j));
		}

		res_complex[i][0] = res_real;
		res_complex[i][1] = res_imagin;
	}
}

void imprime_resul() {
	int i;

	for (i = 0; i < TAM; i++) {
		printf("Indice: %d \t|\t Numero: %lf%+lfi \t|\t Transformada: %lf%+lfi\n", 
				i, val_complex[i][0], val_complex[i][1], res_complex[i][0], res_complex[i][1]);
	}
}
