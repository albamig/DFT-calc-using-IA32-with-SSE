#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 1024
#define PI 3.14
#define ANGULO(j, k) (((-2*PI)/TAM)*(j)*(k)) 

void dftc();
// void dftsse();
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

	dftc();
	imprime_resul();
	// dftsse();
	// imprime_resul();

	return 0;
}

void dftc() {
	int i, j;

	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			res_complex[i][0] += val_complex[j][0] * cos(ANGULO(i, j)) - val_complex[j][1] * sin(ANGULO(i, j));
			res_complex[i][1] += val_complex[j][0] * sin(ANGULO(i, j)) + val_complex[j][1] * cos(ANGULO(i, j));
		}
	}
}

void imprime_resul() {
	int i;

	for (i = 0; i < TAM; i++) {
		printf("Indice: %d \t|\t Numero: %lf%+lfi \t|\t Transformada: %lf%+lfi\n", 
				i, val_complex[i][0], val_complex[i][1], res_complex[i][0], res_complex[i][1]);
	}
}
